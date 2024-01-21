#include <bits/stdc++.h>
using namespace std ;


int squareRoot(int number){
    if(number ==0 || number == 1) return number ;
    long long  ans;
    long long  l=1;
    long long r= number;

    while(l<=r){
        long long  mid = l + (r-l)/2 ;
        if(mid*mid == number)
        {
            ans = mid;
            return ans;
        }
        else if (mid*mid <= number){
            ans = mid;
            l = mid+1;
        }
        else {
            r= mid -1 ;
        }
    }
    return ans;
}