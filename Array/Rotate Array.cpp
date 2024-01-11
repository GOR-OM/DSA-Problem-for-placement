// https://leetcode.com/problems/rotate-array/description/  


// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
    if (n <= 1) {
        return; // No need to rotate for arrays with 0 or 1 element
    }

    // Adjust k to be within the range [0, n)
    k = k % n;

    // Reverse the last k elements
    reverse(nums.begin() + n - k, nums.end());

    // Reverse the first (n - k) elements
    reverse(nums.begin(), nums.begin() + n - k);

    // Reverse the entire array
    reverse(nums.begin(), nums.end());
        
    }
};