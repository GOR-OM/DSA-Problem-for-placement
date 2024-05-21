#include<bits/stdc++.h>
using namespace std;    


double max(double a, double b){
    return a>b?a:b;
}

double solve(vector<pair<double,double>>&coordinate, double x){
    double cost=0;
    for(int i=0;i<coordinate.size();i++){
        cost=max(sqrt(pow(coordinate[i].first-x,2)+pow(coordinate[i].second,2)),cost);
    }
    return cost;
}


int main(){
    while(true){
    int n;
    cin>>n;
    if(n==0)break;

    vector<pair<double,double>>coordinate(n);
    for(int i=0;i<n;i++){
        cin>>coordinate[i].first>>coordinate[i].second;
    }
    double l=-2*1e5;
    double r=2*1e5;
    

    while(r-l>1e-9){
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        double cost1=solve(coordinate,m1);
        double cost2=solve(coordinate,m2);
        
        if(cost1<cost2){
            r=m2;
        }
        else if(cost1>cost2){
            l=m1;
        }
        else{
            l=m1;
            r=m2;
        }
    }
    cout<<fixed<<setprecision(9)<<l<< " "<< solve(coordinate,l)<<endl;

    }
    return 0;
    



}