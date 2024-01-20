// Given a string w, integer array b,  character array x and an integer n. n is the size of array b and array x. Find a substring which has the sum of the ASCII values of its every character, as maximum. ASCII values of some characters are redefined.
// Note: Uppercase & lowercase both will be present in the string w. Array b and Array x contain corresponding redefined ASCII values. For each i, b[i] contain redefined ASCII value of character x[i].

// ```
// Input:
// W = abcde
// N = 1
// X[] = { 'c' }
// B[] = { -1000 }
// Output:
// de
// Explanation:
// Substring "de" has the
// maximum sum of ascii value,
// including c decreases the sum value
// ```


// Example 2:

// Input:
// W = dbfbsdbf 
// N = 2
// X[] = { 'b','s' }
// B[] = { -100, 45  }
// Output:
// dbfbsdbf
// Explanation:
// Substring "dbfbsdbf" has the maximum
// sum of ascii value.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxSum() which takes string W, character array X, integer array B, integer N as length of array X and B as input parameters and returns the substring with the maximum sum of ascii value.


// Expected Time Complexity: O(|W|)
// Expected Auxiliary Space: O(1)


// Constraints:

// 1<=|W|<=100000
// 1<=|X|<=52
// -1000<=Bi<=1000

// Each character of W and A will be from a-z, A-Z.


// Solution:    


#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    //Function to find the maximum sum of the
    //subarray with redefined characters.
    string maxSum(string w, int n, char x[], int b[])
    {
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