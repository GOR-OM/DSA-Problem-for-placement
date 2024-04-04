#include<bits/stdc++.h>
using namespace std ;

void topo(int i, vector<pair<int,int>> adj[], vector<int>& vis, stack<int>&st){
    vis[i]=1 ;
    for(auto it : adj[i]){
        int v = it.first;
        if(!vis[v]){
            topo(v,adj,vis,st);
        }
    }
    st.push(i);
    }



vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];

        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        // topo sort 
        vector<int>vis(N,0);
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topo(i,adj,vis,st);
            }
        }
        vector<int>dis(N,1e9);
        dis[0]=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis[node]+ wt < dis[v]){
                    dis[v]= dis[node]+ wt ;
                }
            }
        }
        return dis;

    }