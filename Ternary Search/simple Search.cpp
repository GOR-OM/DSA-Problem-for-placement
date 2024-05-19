#include   <bits/stdc++.h>
using namespace std;


int ternarySearch(int arr[], int N, int K) 
    { 
       int l=0;
       int r= N-1;
       while(l<=r){
           int w1 = l + (r-l)/3;
           int w2 = r - (r-l)/3;
           if(arr[w1]==K)return 1;
           if(arr[w2]==K)return 1;
           
           if(arr[w1]>K){
               r=w1-1;
           }
           else if(arr[w2]<K){
               l= w2+1;
           }
           else {
               l=w1+1;
               r=w2-1;
           }
       }
       return -1;
    }