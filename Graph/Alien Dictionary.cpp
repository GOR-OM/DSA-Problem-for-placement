#include<bits/stdc++.h>
using namespace std ;

string findOrder(string dict[], int N, int K) {
        vector<int>gr[K];
    for(int i=0;i<N-1;i++){
        int n = dict[i].size();
        int m = dict[i+1].size();
        int j =0;
        while(dict[i][j]==dict[i+1][j]){
            j++;
            if(j>=min(m,n)){
                break;
            }
        }
        if(j<min(m,n)){
            gr[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
        }
    }
    unordered_map<int,int>mp;
    for(int i=0;i<K;i++){
        for(int j : gr[i]){
            mp[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<K;i++){
        if(mp[i]==0){
            q.push(i);
        }
    }
    string ans;
    while(!q.empty()){
        int p = q.front();
        ans.push_back(p+ 'a');
        q.pop();
        for(int l : gr[p]){
            mp[l]--;
            if(mp[l]==0){
                q.push(l);
            }
        }
    }
    if(ans.size()==K){
        return ans;
    }
    else return "";
    }