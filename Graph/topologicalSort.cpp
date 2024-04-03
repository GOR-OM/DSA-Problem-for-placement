#include<bits/stdc++.h>
using namespace std ;

void solve(int i, vector<int>&vis, vector<int> adj[], stack<int>& st){
    vis[i]=1;
    for(auto it : adj[i]){
        if(!vis[it]){
            solve(it,vis,adj,st);
        }
    }
    st.push(i);
}



	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int>vis(V,0);
        stack<int>st;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                solve(i,vis,adj,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
	
	}