//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
unordered_set<string>s;
public:
    int calc(int i, string &A, vector<int>&dp)
    {
        if(i == A.size())
            return 1;
        if(dp[i] != -1)
            return dp[i];
        int ans = 0;
        string temp = "";
        for(int j = i;j<A.size();++j)
        {
            temp += A[j];
            if(s.find(temp) != s.end())
            ans = ans | calc(j+1,A,dp);
        }
        return dp[i] = ans;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        for(int i=0;i<B.size();++i)
            s.insert(B[i]);
        vector<int>dp(A.size(),-1);
        return calc(0,A,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends