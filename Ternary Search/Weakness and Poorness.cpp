#include<bits/stdc++.h> 
using namespace std;







double solve(vector<int>&arr, double x){
    double mx1 =INT_MIN;
    double mx2 = INT_MIN;
    double sum = 0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i]-x;
        mx1 = max(sum,mx1);
        if(sum<0)sum=0;
    }
     sum = 0;
    for(int i=0;i<arr.size();i++){
        sum+= x - arr[i];
        mx1 = max(sum,mx1);
        if(sum<0)sum=0;
    }
    return max(mx1,mx2);
}






int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    double l = -1e4;
    double r = 1e4;
    while(r-l>1e-9){
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        double cost1 = solve(arr,m1);
        double cost2 = solve(arr,m2);
        if(cost1>cost2){
            l=m1;
        }
        else if(cost1<cost2){
            r=m2;
        }
        else{
            l=m1;
            r=m2;
        }
    }
    cout<<fixed<<setprecision(9)<<solve(arr,l)<<endl;
}