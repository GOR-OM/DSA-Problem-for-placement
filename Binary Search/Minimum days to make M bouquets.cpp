// You are given 'n' roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.



// You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.



// Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses. Return -1 if it is not possible.



// Example :
// Input: n = 9,  arr = [ 1, 2, 1, 2, 7, 2, 2, 3, 1 ], k = 3, m = 2

// Output: 3. 

// Explanation: This is because on the 3rd day: all the roses with 'arr[i]' less than equal to 3 have already bloomed, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.

#include<bits/stdc++.h>
using namespace std ;

bool solve(int mid, vector<int>& arr, int k , int m){
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= mid) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}


int roseGarden(vector<int> arr, int k, int m)
{
	if(k*m > arr.size())return -1 ;

    auto mini = min_element(arr.begin(), arr.end());
    int l = *mini;
    auto maxi = max_element(arr.begin(), arr.end());
    int r = *maxi;
    while(l<=r){
        int mid = l +(r-l)/2; 
        if(solve(mid,arr,k,m)){
            r = mid -1;
        }
        else l = mid +1 ;
    }
    return l ;
}