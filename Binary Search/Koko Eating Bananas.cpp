// Problem statement
// A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.



// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.



// Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.



// Example:

// Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7

// Output: 3

#include<bits/stdc++.h>
using namespace std ; 

bool solve(int h, int mid, vector<int>&v){
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+= ceill((double)v[i]/(double)mid);
    }
    return h>=sum ;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    auto maxNumber = max_element(v.begin(), v.end());
    int r = *maxNumber;
    int l = 1 ;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(solve(h,mid,v)){
            r = mid-1;
        }
        else {
            l = mid+1 ;
        }
    }
    return l ;

}