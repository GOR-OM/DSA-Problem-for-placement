// Problem statement
// You are given an array of integers 'arr' and an integer 'limit'.



// Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given integer's limit.



// Note:
// Each result of the division is rounded to the nearest integer greater than or equal to that element. For Example, 7/3 = 3.


#include<bits/stdc++.h>
using namespace std ;

bool solve(int mid, int limit, vector<int>&arr){
    long long sum = 0;
    for(int i=0;i<arr.size();i++){
        sum+= ceil((double)arr[i]/(double)mid);
    }
    return sum<=limit ;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	auto mini = min_element(arr.begin(), arr.end());
    int l = *mini;
    auto maxi = max_element(arr.begin(), arr.end());
    int r = *maxi;
    while(l<=r){
        int mid = l +(r-l)/2; 
        if(solve(mid,limit,arr)){
            r = mid -1;
        }
        else l = mid +1 ;
    }
    return l ;
}