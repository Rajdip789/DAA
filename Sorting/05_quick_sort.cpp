/**
 *	Quick sort - follows Divide & Conquer approach.	
 *	Unstable sort algorithm
 *	
 *	TC - O(N*logN) 
 *	Worst case TC - O(N^2), when the array is sorted (natual/reverse), 
 *	i.e. maximally unbalanced, each time pick the largest or smallest element as pivot
**/

#include <iostream>
#include <vector>
using namespace std;

// Lomuto partition scheme
int lomutoPartition(vector<int> &nums, int low, int high) {
	int pivot = nums[high];
	int loc = low;

	for(int i = low; i < high; i++) {
		if(nums[i] < pivot) {
			swap(nums[i], nums[loc++]);
		} 
	}

	swap(nums[loc], nums[high]);
	return loc;
}

// Hoare partition scheme
int hoarePartition(vector<int> &nums, int low, int high) {
	int pivot = nums[low];
	int i = low - 1, j = high + 1;
	
	while(true) {
		do {
			i += 1;
		} while(nums[i] < pivot);
		
		do {
			j -= 1;
		} while(nums[j] > pivot);
		
		if(i < j) swap(nums[i], nums[j]);
		else return j;
	}	

	return j;
}

void quickSort(vector<int> &nums, int low, int high) {
	if(low < high) {
		int pi = lomutoPartition(nums, low, high);
		//int pi = hoarePartition(nums, low, high);		// get the index of partition
		//quickSort(nums, low, pi);						// use this in case of hoarePartition
		quickSort(nums, low, pi-1);					
		quickSort(nums, pi + 1, high);
	}	
}

int main() {
	vector<int> nums = {5, 2, 4, 6, 1, 3};

	quickSort(nums, 0, nums.size() - 1);
	
	cout << "After sorting the elements are:\n";
	for(int num : nums) 
		cout << num << " ";

	return 0;
}
