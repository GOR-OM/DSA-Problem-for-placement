

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> & nums, int target){
    int left = 0, right = nums.size()-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid+1;
        else right = mid-1;
    }
    return -1;
}

// Recursive Binary Search  

int binarySearch(vector<int> & nums, int target, int left, int right){
    if(left > right) return -1;
    int mid = left + (right-left)/2;
    if(nums[mid] == target) return mid;
    else if(nums[mid] < target) return binarySearch(nums, target, mid+1, right);
    else return binarySearch(nums, target, left, mid-1);
}