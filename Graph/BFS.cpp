#include<bits/stdc++.h>
using namespace std ;




vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    // Create an adjacency list to represent the graph
    vector<vector<int>> adjList(vertex + 1);

    // Populate the adjacency list based on the given edges
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Assuming an undirected graph
    }

    // Data structure to store the result of BFS traversal
    vector<int> result;

    // Boolean array to keep track of visited vertices
    vector<bool> visited(vertex + 1, false);

    // Queue for BFS traversal
    queue<int> bfsQueue;

    // Start BFS from the specified vertex
    bfsQueue.push(vertex);
    visited[vertex] = true;

    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();

        result.push_back(currentVertex);

        // Visit all adjacent vertices of the current vertex
        for (int adjacentVertex : adjList[currentVertex]) {
            if (!visited[adjacentVertex]) {
                bfsQueue.push(adjacentVertex);
                visited[adjacentVertex] = true;
            }
        }
    }

    return result;
}



vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int>ans;
    vector<bool>visited(V,false);
    queue<int>q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for(int i : adj[v]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }


    }
    return ans ;

}