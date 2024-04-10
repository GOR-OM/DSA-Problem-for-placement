#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(V,INT_MAX);
        dis[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int distance = pq.top().first;
            int vertex = pq.top().second;
            pq.pop();
            for(auto it : adj[vertex]){
                int weight = it[1];
                int adjNode = it[0];
                if(distance + weight < dis[adjNode]){
                    dis[adjNode] = distance + weight;
                    pq.push({dis[adjNode],adjNode});
                }
            }
        }
        return dis;
    }