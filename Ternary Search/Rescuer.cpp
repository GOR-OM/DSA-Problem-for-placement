#include<bits/stdc++.h>
using namespace std;


double solve(double x1,double x2,double y1,double y2,double v1,double v2,double val){
    double cost =0;
    cost += sqrt(pow(x1-val,2)+ pow(y1,2))/v1 ;
    cost += sqrt(pow(x2-val,2)+ pow(y2,2))/v2;
    return cost;
}





int main(){
    int t;
    cin>>t;
    while(t--){
        double x1,x2,y1,y2,v1,v2;
        cin>>x1>>y1>>x2>>y2>>v1>>v2;

        double l = min(x1,x2);
        double r = max(x1,x2);
        while(r-l>1e-5){
            double m1 = l + (r-l)/3;
            double m2 = r- (r-l)/3;

            double cm1 = solve(x1,x2,y1,y2,v1,v2,m1);
            double cm2 = solve(x1,x2,y1,y2,v1,v2,m2);

            if(cm1>cm2){
                l = m1;
            }
            else if(cm1<cm2){
                r= m2;
            }
            else {
                l=m1;
                r=m2;
            }
        }
        cout<<fixed<<setprecision(5)<<solve(x1,x2,y1,y2,v1,v2,l)<<endl;

    }

    return 0;
}