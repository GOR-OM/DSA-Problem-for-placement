


# include <bits/stdc++.h>   
using namespace std;


vector<int> rearrangeArray(vector<int> &A)
{
    vector<int>ans(A.size());
    int n= 0;
    int p = 1;
    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            ans[n]=A[i];
            n+=2;
        }
        else{
            ans[p]=A[i];
            p+=2;
        }
    }
    return ans;

}


// Varieties of this problem:

// 1. Rearrange positive and negative numbers in O(n) time and O(1) extra space

vector<int> rearrangeArray(vector<int> &A)
{
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            neg.push_back(A[i]);
        }
        else{
            pos.push_back(A[i]);
        }
    for(int i=0;i<min(pos.size(),neg.size());i++){
        A[2*i]=pos[i];
        A[2*i+1]=neg[i];
    }
    if(pos.size()>neg.size()){
        while(i<pos.size()){
            A[2*neg.size()+i]=pos[i];
            i++;
        }
    }
    else{
        while(i<neg.size()){
            A[2*pos.size()+i]=neg[i];
            i++;
        }
    }

    }
}


int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<int> ans = rearrangeArray(A);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

