#include<bits/stdc++.h>
using namespace std;

int timer =1;
void dfs(int node ,int parents, vector<int>&vis, vector<int>&tin, vector<int>&low, vector<int> adj[], vector<vector<int>>&bridges){
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for(auto it : adj[node]){
        if(it == parents) continue;
        if(!vis[it]){
            dfs(it, node, vis, tin, low, adj, bridges);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                bridges.push_back({node, it});
            }
        }else{
            low[node] = min(low[node], tin[it]);
        }
    }
}



vector<vector<int>> CriticalComponents (int n,  vector<vector<int>>&connections){
    vector<int> adj[n];
    for(auto x: connections){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    vector<int>vis(n,0);
    vector<int>tin(n);
    vector<int>low(n);
    vector<vector<int>> bridges;
    dfs(0, -1, vis, tin, low, adj, bridges);
    return bridges;
    
}