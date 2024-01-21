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