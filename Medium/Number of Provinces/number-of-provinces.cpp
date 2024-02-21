//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int numProvinces(vector<vector<int>> adj, int V) {
    vector<int>adjj[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1){
                adjj[i].push_back(j);
            }
        }
    }
    int ans=0;
    vector<bool>vis(V,false);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){

        
        vis[i]=true;
        st.push(i);
        ans++;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            for(int adjs : adjj[top]){
                if(!vis[adjs]){
                    st.push(adjs);
                    vis[adjs]=true;
                }
            }
        }
    }
    }
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends