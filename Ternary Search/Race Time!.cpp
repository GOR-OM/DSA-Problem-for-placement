#include<bits/stdc++.h>
using namespace std;


double solve(vector<pair<int,int>>&racer, double x){
    
    double mini=INT_MAX;
    double maxi=INT_MIN;
    for(int i=0;i<racer.size();i++){
        mini = min(racer[i].first*x + racer[i].second,mini);
        maxi = max(racer[i].first*x + racer[i].second,maxi);
        
    }
    return maxi-mini;
}




int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>racer(n);
    for(int i=0;i<n;i++){
        cin>>racer[i].first>>racer[i].second;
    }

    double l=0;
    double r=k;
    while (r-l>1e-7)
    {
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;

        double cost1= solve(racer,m1);
        double cost2= solve(racer,m2);
        
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
    cout<<fixed<<setprecision(6)<<solve(racer,l)<<endl;
    
}