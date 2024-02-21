//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   void dfsRecursive(int vertex, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
    visited[vertex] = true;
    result.push_back(vertex);

    for (int adjacentVertex : adj[vertex]) {
        if (!visited[adjacentVertex]) {
            dfsRecursive(adjacentVertex, adj, visited, result);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> result;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfsRecursive(i, adj, visited, result);
        }
    }

    return result;
}
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends