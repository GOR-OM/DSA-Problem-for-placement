# include <bits/stdc++.h>
using namespace std;

void nextPermutation (vector<int> nums){
    next_permutation(nums.begin(), nums.end());
}


// Other method :)

vector<int> nextGreaterPermutation(vector<int> & nums){
    int index = -1;
    for(int i = nums.size()-1; i > 0; i--){
        if(nums[i] > nums[i-1]){
            index = i-1;
            break;
        }
    }
    if(index == -1){
        reverse(nums.begin(), nums.end());
        return nums;
    }
    for(int i= nums.size()-1; i > index; i--){
        if(nums[i] > nums[index]){
            swap(nums[i], nums[index]);
            break;
        }
    }
    reverse(nums.begin()+index+1, nums.end());
}