#include<bits/stdc++.h>
using namespace std;


vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
     vector<pair<int,int>>edg[n];
     for(int i=0;i<n;i++){
        edg[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        edg[edges[i][1]].push_back({edges[i][0],edges[i][2]});
     }

     vector<vector<pair<int,int>>>abc(n);
     for(int i=0;i<n;i++){
        abc[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        abc[edges[i][1]].push_back({edges[i][0],edges[i][2]});
     }
        vector<int>ans;
        for(int i=0;i<query.size();i++){
            int start = query[i][0];
            int end = query[i][1];
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            vector<int>dis(n,1e9);
            dis[start]= INT_MAX;
            pq.push({dis[start],start});
            while(!pq.empty()){
                auto it  =pq.top();
                pq.pop();
                int distance  = it.first;
                int node = it.second;
                for(auto nodes : abc[node]){
                    int newNode = nodes.first;
                    int weight = nodes.second;
                    if(weight & distance < dis[newNode]){
                        dis[newNode] = weight & distance;
                        pq.push({dis[newNode],newNode});
                    }
                }
            }
            if(dis[end]=1e9){
                ans.push_back(-1);
            }
            else{
                ans.push_back(dis[end]);
            }
        }
        return ans;
}