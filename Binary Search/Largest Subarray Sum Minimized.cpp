#include<bits/stdc++.h>
using namespace std;


int solve(int mid,vector<int>&arr ,int k){
    int painter = 1 ;
    int totalPaint = 0;
    for(int i=0;i<arr.size();i++){
        if(totalPaint +arr[i]<=mid){
            totalPaint +=arr[i];
        }
        else{
            painter++;
            totalPaint = arr[i];
        }

    }
    return painter ;
}


int largestSubarraySumMinimized(vector<int> a, int k) {
    int l = *max_element(a.begin(),a.end());
    int r = accumulate(a.begin(),a.end(),0);
    while(l<=r)
    {
        int mid = l +(r-l)/2 ;
        int painter  = solve(mid,a,k);
        if(painter>k){
            l = mid+1 ;
        }
        else r = mid-1 ;
    }
    return l ;
}