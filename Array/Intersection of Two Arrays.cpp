// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.



// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.


// https://leetcode.com/problems/intersection-of-two-arrays/description/ 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> result;

    for (int num : set1) {
        if (set2.count(num)) {
            result.push_back(num);
        }
    }

    return result;
    }
};



// if given that tow arrays are sorted, then we can use two pointers to find the intersection

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]>nums2[j])
            {
                j++;
            }
            else if (nums1[i]<nums2[j]){
                i++;
            }
            else {
                if (ans.empty() || ans.back() != nums1[i]){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }