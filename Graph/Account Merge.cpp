// Given a list of accounts of size n where each element accounts [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
// Geek wants you to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.

// Note: Accounts themselves can be returned in any order.

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>> &details)
{
    int n = details.size();
    DisjointSet ds(n);
    sort(details.begin(), details.end());
    unordered_map<string, int> mapMailNode;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < details[i].size(); j++)
        {
            string mail = details[i][j];
            if (mapMailNode.find(mail) == mapMailNode.end())
            {
                mapMailNode[mail] = i;
            }
            else
            {
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }

    vector<string> mergedMail[n];
    for (auto it : mapMailNode)
    {
        string mail = it.first;
        int node = ds.findUPar(it.second);
        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;

    for (int i = 0; i < n; i++)
    {
        if (mergedMail[i].size() == 0)
            continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for (auto it : mergedMail[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
                                       {"John", "j4@com"},
                                       {"Raj", "r1@com", "r2@com"},
                                       {"John", "j1@com", "j5@com"},
                                       {"Raj", "r2@com", "r3@com"},
                                       {"Mary", "m1@com"}};

       vector<vector<string>> ans = accountsMerge(accounts);
    for (auto acc : ans)
    {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++)
        {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
