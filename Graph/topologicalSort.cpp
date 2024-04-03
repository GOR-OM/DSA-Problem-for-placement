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

// BFS 



class Solution {
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
};