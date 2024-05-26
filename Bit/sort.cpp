

#include<bits/stdc++.h>
using namespace std;







vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int a,int b){
            int count1 = __builtin_popcount(a);
            int count2 = __builtin_popcount(b);
            if(count1==count2){
                return a<b;
            }
            return count1<count2;
        });
    }