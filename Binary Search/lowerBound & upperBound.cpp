
// Lower bound is the first element in the range which is greater than or equal to the given value.
// Upper bound is the first element in the range which is greater than the given value.

// lower_bound() returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
// upper_bound() returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
// arr[index] >= val (lower_bound)
// arr[index] > val (upper_bound)

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> & nums, int target){
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// directly using lower_bound() function
int lowerBound(vector<int> & nums, int target){
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int upperBound(vector<int> & nums, int target){
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// directly using upper_bound() function

int upperBound(vector<int> & nums, int target){
    return upper_bound(nums.begin(), nums.end(), target) - nums.begin();
}