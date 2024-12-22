/**
 *	Insertion sort - like sorting a hand of playing cards.
 *	Good running time for almost sorted arrays.	
 *	~ (N^2)/2 comparisons and exchanges.
 *	Stable sort algorithm
 *
 *	TC - O(N^2)
**/

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &nums) {
	int n = nums.size();

	for(int i = 1; i < n; i++) {
		int j = i - 1;
		int key = nums[i];	
		
		while(j >= 0 && nums[j] > key) {
			nums[j+1] = nums[j];
			j--;
		}
		
		nums[j+1] = key;
		
		// for visualization
		cout << "pass " << i << ":	 ";
		for(int num : nums)	cout << num << " ";
		cout << endl;
	}
}

int main() {
	vector<int> nums = {5, 2, 4, 6, 1, 3};

	insertionSort(nums);
	
	cout << "\nAfter sorting the elements are:\n";
	for(int num : nums) 
		cout << num << " ";

	return 0;
}
