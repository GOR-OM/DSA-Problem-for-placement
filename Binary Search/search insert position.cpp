// Search Insert Position

// Problem statement
// You are given a sorted array 'arr' of distinct values and a target value 'm'.



// You need to search for the index of the target value in the array.



// Note:
// If the value is present in the array, return its index.
// If the value is absent, determine the index where it would be inserted in the array while maintaining the sorted order. 


// Example:
// Input:  arr = [1, 2, 4, 7],  m = 6 

// Output: 3
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int m)
{
	return lower_bound(arr.begin(), arr.end(), m) - arr.begin();
}

int searchInsert(vector<int>& arr, int m)
{
    int low = 0, n = arr.size();
    int high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= m) {
            ans = mid;
            high= mid - 1;
        } else {
            low = mid+1;
        }
    }
    return ans;
}