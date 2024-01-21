

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] >= nums[low]) {
            if(target >= nums[low] && target < nums[mid]) high = mid-1;
            else low = mid+1;
        }
        else {
            if(target <= nums[high] && target > nums[mid]) low = mid+1;
            else high = mid-1;
        }
    }
    return -1;
}

// OR 
int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}
