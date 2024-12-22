/**
 *	Selection sort - Each time find the smallest element in the remaining array and place in its correct position.
 *	Efficient when sorting files with huge records and small keys.	
 *	~ (N^2)/2 comparisons and n exchanges.
 *	Unstable sort algorithm
 *	
 *	TC - O(N^2)
**/

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &nums) {
	int n = nums.size();
	
	for(int i = 0; i < n; i++) {
		int smallest = i;

		for(int j = i+1; j < n; j++) {
		    if(nums[j] < nums[smallest]) {
			     smallest = j;
		    }
	    }  
	    
		swap(nums[i], nums[smallest]);
	
	    // for visualization
		cout << "pass " << i << ":	 ";
		for(int num : nums)	cout << num << " ";
		cout << endl;
	}
}

int main() {
	vector<int> nums = {5, 2, 4, 6, 1, 3};

	selectionSort(nums);
	
	cout << "\nAfter sorting the elements are:\n";
	for(int num : nums) 
		cout << num << " ";

	return 0;
}
