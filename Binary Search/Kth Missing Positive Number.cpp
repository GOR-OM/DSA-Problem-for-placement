#include<bits/stdc++.h>
using namespace std ;


// O(n)
int missingK(vector < int > vec, int n, int k) {
    if(vec[0]>k)return k ;
    int ans=k;
    for(int i=0;i<vec.size();i++){
        if(vec[i]<ans){
            ans++;
        }
        else return ans ;
    }
    return -1 ;
}

// O(log(n))



int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}


