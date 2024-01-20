//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
int a[26]={},A[26]={},maxi=INT_MIN,cnt=0;
        string ans="",temp="";
        for(int i=0;i<26;i++) {
            a[i]=i+'a'; 
            A[i]=i+'A';
        }
        for(int i=0;i<n;i++) {
            if(x[i]<='Z') A[x[i]-'A']=b[i];
            else a[x[i]-'a']=b[i];
        }
        for(int i=0;i<w.size();i++){
            if(w[i]<='Z') cnt+=A[w[i]-'A']; 
            else cnt+=a[w[i]-'a'];
            temp+=w[i];
            if(cnt>maxi){
                maxi=cnt;  ans=temp;
            }
            if(cnt<0) {
                cnt=0; temp="";
            }
        }
        return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends