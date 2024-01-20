# include <bits/stdc++.h>
using namespace std;


int  maxProfit(vector<int>& price){
    int profit = 0;
    int mini = price[0];
    int maxProfit = 0;
    for(int i=1;i<price.size();i++){
        profit = price[i]-mini;
        if(profit>maxProfit){
            maxProfit = profit;
        }
        if(price[i]<mini){
            mini = price[i];
        }
    }
    return maxProfit;
}