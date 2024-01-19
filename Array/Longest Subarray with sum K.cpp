


#include<bits/stdc++.h>
using namespace std;

  int lenOfLongSubarr(int A[],  int N, int K) 
    {  // Complete the function
        int maxLen=0;
        int sum=0;
        map<int,int> mpp;
        
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum == K){
                maxLen=i+1;
            }
            if(mpp.find(sum-K) != mpp.end()){
                maxLen = max(maxLen,i-mpp[sum-K]);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        
        return maxLen;
    } 

// other method two pointer approach 


int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        long long sum = A[0];
        int left =0;
        int right = 0;
        int maxlen = 0;
        while(right<N){
        while(left<right && sum>K){
            sum-=A[left];
                left++;
            }
            if(sum==K){
                maxlen = max(maxlen, right-left+1);
            }
            right++;
            if(right<N){
                sum+=A[right];
            }
        }
        return maxlen;

    } 


