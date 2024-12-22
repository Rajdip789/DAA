/**
 *	Merge sort - follows Divide & Conquer and Merge approach.
 *	Efficient in sorting a huge randomly ordered fill of small records.	
 *	
 *	Stable sort algorithm
 *	
 *	TC - O(N*logN) / SC - O(N)
**/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high) {
	int left = low;
	int right = mid + 1;
	
	vector<int> temp;

	while(left <= mid && right <= high) {
		if(nums[left] <= nums[right]){
			temp.push_back(nums[left++]);
		} else {
			temp.push_back(nums[right++]);
		}
	}

	while(left <= mid) temp.push_back(nums[left++]);

	while(right <= high) temp.push_back(nums[right++]);
	
	for(int i = low; i <= high; i++) {
		nums[i] = temp[i-low];
	}
}

void mergeSort(vector<int> &nums, int low, int high) {
	if(low < high) {
		int mid = (low + high) / 2;

		mergeSort(nums, low, mid);
		mergeSort(nums, mid + 1, high);
		merge(nums, low, mid, high);
	}	
}

int main() {
	vector<int> nums = {5, 2, 4, 6, 1, 3};

	mergeSort(nums, 0, nums.size() - 1);
	
	cout << "After sorting the elements are:\n";
	for(int num : nums) 
		cout << num << " ";

	return 0;
}
