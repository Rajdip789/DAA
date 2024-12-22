/**
 *	Bubble sort - repeatedly pass through the array, swaps adjacent elements that are out of order.
 *	Stable sort algorithm.
 *	~ (N^2)/2 comparisons and exchanges.
 *
 *	TC - O(N^2)
**/

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &nums) {
	int n = nums.size();
	
	for(int i = 0; i < n; i++) {		
		for(int j = n-1; j > i; j--) {
			if(nums[j] < nums[j-1]) {
				swap(nums[j], nums[j-1]);
			}
		}

		// for visualization
		cout << "pass " << i << ":	 ";
		for(int num : nums)	cout << num << " ";
		cout << endl;
	}
}

int main() {
	vector<int> nums = {5, 2, 4, 6, 1, 3};

	bubbleSort(nums);
	
	cout << "\nAfter sorting the elements are:\n";
	for(int num : nums) 
		cout << num << " ";

	return 0;
}
