#include<bits/stdc++.h>
using namespace std;


bool solve(vector<vector<int>>& graph , vector<int>& vis, vector<int>& pathVis, vector<int>&check,int i ){
    vis[i]=1;
    pathVis[i]=1;
    
    for(auto j : graph[i]){
        if(!vis[j]){
            if(solve(graph,vis,pathVis,check,j)){
                    check[i]=0;
                    return true;
            }
        }
        else if(pathVis[j]){
                check[i]=0;
                return true;
            }
    }
    check[i]=1;
    pathVis[i]=0;
    return false;
}


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int>check(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(graph, vis,pathVis,check,i);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]==1)ans.push_back(i);
        }
        return ans;
    }