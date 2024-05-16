#include<bits/stdc++.h>
using namespace std;


// Given a tree with n nodes and edge connection between them . The tree is rooted at node 1. Your task is to remove minimum number of edges from the given tree such that the tree converts into disjoint union tree so that nodes of connected component left is divisible by 2.

int dfs(int node,vector<int>adj[],vector<int>&vis,int & ans){
    vis[node] = 1;
    int sum=1;

    for(auto it : adj[node]){
        if(!vis[it]){
            int x = dfs(it,adj,vis,ans);
            if(x%2 == 0){
                ans++;
            }
            sum+=x;
        }
    }
    auto it = adj[node];
    if(it.size() == 0){
        return 1;
    }
    else return sum;
}



int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    vector<int>adj[n+1];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        int ans = 0;
        dfs(1,adj,vis,ans);
        return ans;

	}