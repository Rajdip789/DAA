/**
 *	Counting Sort is a linear time, non-comparison-based, stable sorting algorithm. 
 *  It is efficient when the range of input values is small compared to the no of elements to be sorted. 
 *  
 *  The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array 
 *  and use that information to place the elements in their correct sorted positions..	
 *	
 *	TC - O(N + K) / SC - O(N + K) 
 *  N = size of input array, K = range of elements, i.e. size of count array
**/

#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &nums) {
    int k = 0;

    for(int num : nums) k = max(k, num);

    vector<int> count(k + 1, 0);

    for(int num : nums) {
        count[num]++;
    }

    int index = 0;
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j < count[i]; j++) {
            nums[index] = i;
            index++;
        }
    }
}

void countSortStable(vector<int> &nums) {
    int n = nums.size();

    int maxVal = *max_element(nums.begin(), nums.end());
    int minVal = *min_element(nums.begin(), nums.end());
    int k = maxVal - minVal + 1;

    vector<int> count(k + 1, 0);

    for(int num : nums) count[num - minVal]++;
    
    for(int i = 1; i < k; ++i) count[i] += count[i - 1];
    

    vector<int> output(nums.size());

    for(int i = nums.size() - 1; i >= 0; i--) {        // Traverse in reverse order for stability
        output[count[nums[i] - minVal] - 1] = nums[i];
        count[nums[i] - minVal]--;
    }

    for(int i = 0; i < nums.size(); ++i) nums[i] = output[i];
}

int main() {
	vector<int> nums = {5, 6, 5, 2, 4, 6, 6};

	//countSort(nums);
	countSortStable(nums);
	
	cout << "After sorting the elements are:\n";
	for(int num : nums) 
		cout << num << " ";

	return 0;
}
