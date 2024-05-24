#include<bits/stdc++.h>
using namespace std;





int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cumSumFreq;
    cumSumFreq[0] = 1; // Base case: one way to have a cumulative sum of 0

    int cumSum = 0;
    int count = 0;

    for (int num : nums) {
        cumSum += num;

        if (cumSumFreq.find(cumSum - k) != cumSumFreq.end()) {
            count += cumSumFreq[cumSum - k];
        }

        cumSumFreq[cumSum]++;
    }

    return count;
    }

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    cout<<subarraySum(nums,k)<<endl;
    }
}