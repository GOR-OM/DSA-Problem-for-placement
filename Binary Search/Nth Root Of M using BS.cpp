#include<bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m) {
if(m==0 || m==1)return  m;
if(n==1)return m ;
int l = 1; 
int r = m;
int ans;
    while(l<=r){
        int i = l + (r - l)/2 ;
        if(pow(i,n)== m){
            return i ; 
        }
        else if (pow(i,n) <= m){
            l = i+1;
        }
        else {
            r = i-1 ;
        }
    }
    return -1;
}