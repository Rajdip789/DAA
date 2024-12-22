/**
 *	Heap - is a nearly complete binary tree with the following properties
 *	1. Structural property : all the levels are full except possibly the last one, which is filled from left to right
 *	2. Order (Heap) property : fo any node x - Parent(X) >= x	i.e. the root is the maximum element in the heap.
 *	
 *	Max-heap : largest element at root, for all nodes i excluding root: A[Parent(i)] >= A[i]
 *	Max-heap : smallest element at root, for all nodes i excluding root: A[Parent(i)] <= A[i]
 *
 *	Heap sort: build_max_heap -> heap_sort (Used in priority queue implementation)
 *	Unstable sort algorithm
 * 	
 *	TC - O(N) + O(N*logN) ~ O(N*logN)
**/

#include <iostream>
#include <vector>
using namespace std;

// O(logN)
void max_heapify(vector<int> &nums, int ind, int n) {
	int largest = ind;
	int left = 2*ind + 1;
	int right = 2*ind + 2;
	
	if(left < n && nums[left] > nums[ind])
		largest = left;

	if(right < n && nums[right] > nums[largest])
		largest = right;

	if(largest != ind) {
		swap(nums[ind], nums[largest]);
		max_heapify(nums, largest, n);
	}
}

// O(N)
void build_maxheap(vector<int> &nums, int n) {
	for(int i = n/2-1; i >= 0; i--)
		max_heapify(nums, i, n);
}

// O(N*logN)
void heapSort(vector<int> &nums) {
	int n = nums.size();
	build_maxheap(nums, n);

	for(int i = n - 1; i > 0; i--) { 
		swap(nums[i], nums[0]);
		max_heapify(nums, 0, i);
	}	
}

int main() {
	vector<int> nums = {5, 2, 4, 6, 1, 3};

	heapSort(nums);
	
	cout << "After sorting the elements are:\n";
	for(int num : nums) 
		cout << num << " ";

	return 0;
}
