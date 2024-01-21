// First and Last Occurrences in Array
// find using lower_bound and upper_bound

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findFirstAndLast(vector<int> & nums, int target){
    int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (left > right || nums[left] != target || right >= nums.size()) {
        return {-1, -1};
    }
    return {left, right};
}

// using simple binary search

pair<int, int> findFirstAndLast(vector<int> & nums, int target){
    int left = 0, right = nums.size()-1;
    int first = -1, last = -1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
            first = mid;
            right = mid-1;
        }
        else if(nums[mid] < target) left = mid+1;
        else right = mid-1;
    }
    left = 0, right = nums.size()-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
            last = mid;
            left = mid+1;
        }
        else if(nums[mid] < target) left = mid+1;
        else right = mid-1;
    }
    return {first, last};
}