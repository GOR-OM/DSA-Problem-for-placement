//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	int dp[n+1];
    	fill_n(dp,n+1,0);
    	
    	int a[] ={3,5,10};
    	   
    	for(int j=0;j<3;j++){
    	    for(int i=3;i<=n;i++){
    	        if(i-a[j]==0)
    	        {
    	            dp[i]+=1;
    	        }
    	        else if((i-a[j]>0) and dp[i-a[j]]){
    	            dp[i]+=dp[i-a[j]];
    	        }
    	    }
    	}
    	
    	return dp[n];
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends