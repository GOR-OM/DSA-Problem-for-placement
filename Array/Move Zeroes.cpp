// https://leetcode.com/problems/move-zeroes/description/   

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.



// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]



# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Move non-zero element to the front
                nums[nonZeroIndex++] = nums[i];
            }
        }

        // Fill the remaining elements with zeros
        while (nonZeroIndex < nums.size()) {
            nums[nonZeroIndex++] = 0;
        }
    }
};