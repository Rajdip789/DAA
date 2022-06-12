//Implement a program in C to solve the 15-puzzle problem using Branch and Bound technique.
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define PuzzleSize 4

struct Node {
	int Node[4][4];
	int HV;
	int Parent;
};

struct Node NodeList[50];
int GoalNode[4][4], NodeNo=0,ChildList[4],ChildListIndex,LiveNodeNo,LiveNodeList[50];
void LCSearch(int);
int isGoalNode(int);
int FindValue(int);
void Add(int);
int Delete(int);
void FindChild(int);
void CreateNode(int ,int ,int ,int ,int );
void EmptyLiveNodeList();
void Print(int,int);

void main(void)
{
   	int s, G[20][20],n,i,j;
   	printf("************Enter '0' for blank tiles***************\n");
   	printf("Enter goal node\n");
   	for(i=0;i<PuzzleSize;i++)
   		for(j=0;j<PuzzleSize;j++)
   			scanf("%d",&GoalNode[i][j]);
   	
	printf("Enter the initial node\n");
   	for(i=0;i<PuzzleSize;i++)
   		for(j=0;j<PuzzleSize;j++)
   			scanf("%d",&NodeList[1].Node[i][j]);
	
	NodeList[1].Parent=-1;
	NodeNo++;
	LCSearch (1);
    
   	printf("\n");

}

void LCSearch (int t) {
// Search t for an answer node
	int E,i;
	if(isGoalNode(t)) {
		Print(1,1);
		return;
	}
	
    E=t; // E-node
    
    EmptyLiveNodeList();
    do {	
    	if(NodeNo>50)
    		return;
		FindChild(E);
        for(i=0;i<ChildListIndex;i++) {
            if (isGoalNode(ChildList[i])) {
				Print(ChildList[i],E); 
				return;
			}
            Add(ChildList[i]); //Add x as new live node.
            
        }
        if (LiveNodeNo==0) {
			printf("No answer node"); 
			return;
		}
        E=Least(); 	//Find new E-node with least cost from the queue of live node
			// and remove from queue.
    } while(1);
}

int isGoalNode(int t) {
	int i,j;
	for(i=0;i<PuzzleSize;i++)
   		for(j=0;j<PuzzleSize;j++)
   			if(GoalNode[i][j]!=NodeList[t].Node[i][j])
   				return FALSE;
	return TRUE;
}

void FindChild(int t) {
	int i,j,x,y;
	ChildListIndex=0;
	for(i=0;i<PuzzleSize;i++)
		ChildList[i]=0;
	for(i=0;i<PuzzleSize;i++)
   		for(j=0;j<PuzzleSize;j++)
   			if(NodeList[t].Node[i][j]==0) {
			   	x=i;
			   	y=j;
			   	break;
		   	}
  	/****************Up Move*******************/
  	if((x-1)>=0)
  		CreateNode(t,x,y,x-1,y);
	/****************Down Move*******************/
  	if((x+1)<PuzzleSize)
  		CreateNode(t,x,y,x+1,y);	
 	/****************Left Move*******************/
  	if((y-1)>=0)
  		CreateNode(t,x,y,x,y-1);
	/****************Right Move*******************/
  	if((y+1)<PuzzleSize)
  		CreateNode(t,x,y,x,y+1);
}
void CreateNode(int t,int x,int y,int x1,int y1) {
	int i,j,k;
	NodeNo++;
	for(i=0;i<PuzzleSize;i++)	
   		for(j=0;j<PuzzleSize;j++)
   			NodeList[NodeNo].Node[i][j]=NodeList[t].Node[i][j];
	k=NodeList[NodeNo].Node[x][y];
	NodeList[NodeNo].Node[x][y]=NodeList[NodeNo].Node[x1][y1];
	NodeList[NodeNo].Node[x1][y1]=k;
	NodeList[NodeNo].HV=FindValue(NodeNo);	
	NodeList[NodeNo].Parent=t;
	ChildList[ChildListIndex]=NodeNo;
	ChildListIndex++;
}
int FindValue(int t) {
	int i,j,val=0;
	for(i=0;i<PuzzleSize;i++)
   		for(j=0;j<PuzzleSize;j++)
   			if(GoalNode[i][j]!=NodeList[t].Node[i][j] && NodeList[t].Node[i][j]!=0)	
   				val++;
	return(val);
}
int Least() {
	int i,min=9999,index,pos;
	for(i=0;i<LiveNodeNo;i++)
		if(min>NodeList[LiveNodeList[i]].HV)
		{
			min=NodeList[LiveNodeList[i]].HV;
			index=LiveNodeList[i];
			pos=i;
		}
	Delete(pos);
	return index;
}
void EmptyLiveNodeList() {
	LiveNodeNo=0;
}
void Add(int item) {
	LiveNodeList[LiveNodeNo]=item;
	LiveNodeNo++;
}

int Delete(int pos) {
	int i;
	for(i=pos;i<LiveNodeNo;i++)	
		LiveNodeList[i]=LiveNodeList[i+1];
	LiveNodeNo--;
}

void Print(int n, int E) {
	int i,j,k;
	k=n;
	
	do{
		for(i=0;i<PuzzleSize;i++) {
   			for(j=0;j<PuzzleSize;j++)
   				printf("\t%d",NodeList[k].Node[i][j]);
			printf("\n");
		}
		printf("\t\t\t|\n");
		printf("\t\t\t|\n");
		k=NodeList[k].Parent;
		if(k==-1)
			break;
	}while(1);
	
	printf("\nNode No %d\n",E);
}
