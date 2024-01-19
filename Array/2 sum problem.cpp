
#include <bits/stdc++.h>
using namespace std;

bool hasArrayTwoCandidates(vector<int>arr, int n, int x) {
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] == x)
            return true;
        else if (arr[i] + arr[j] < x)
            i++;
        else
            j--;
    }
    return false;
}

// if we have to return index of two element 

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(target - nums[i]) != mp.end()) {
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]] = i;
    }
    return ans;
}