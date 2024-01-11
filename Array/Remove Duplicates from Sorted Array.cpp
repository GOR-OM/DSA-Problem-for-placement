// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/ 

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int ans=1;
        int a  =nums[0];
        for(int i=1;i<nums.size();i++){
            if(a!=nums[i]){
                a = nums[i];
                ans++;
            }
            else{
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        
        return ans;
    }
};