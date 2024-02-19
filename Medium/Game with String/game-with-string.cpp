//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        map<char, int> mp;
        for(auto ch:s)mp[ch]++;
        multiset<int> ms;
        for(auto val: mp) ms.insert(val.second);
        while(k--){
            auto it = ms.end(); it--;
            auto num = *it-1;
            ms.erase(it);
            ms.insert(num);
            it = ms.end(); it--;
            if (*it <= 0) break;
        }
        int ans=0;
        for(auto val:ms) ans+=(val*val);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends