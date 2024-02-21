#include<bits/stdc++.h>
using namespace std;


vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> result;
    vector<bool> visited(V, false);
    stack<int> dfsStack;

    // Start DFS from each unvisited vertex
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfsStack.push(i);
            visited[i] = true;

            while (!dfsStack.empty()) {
                int currentVertex = dfsStack.top();
                dfsStack.pop();
                result.push_back(currentVertex);

                // Visit all adjacent vertices of the current vertex
                for (int adjacentVertex : adj[currentVertex]) {
                    if (!visited[adjacentVertex]) {
                        dfsStack.push(adjacentVertex);
                        visited[adjacentVertex] = true;
                    }
                }
            }
        }
    }

    return result;
}


// using recursion :) 

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