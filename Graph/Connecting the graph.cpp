// You are given a graph with n vertices and m edges.

// You can remove one edge from anywhere and add that edge between any two vertices in one operation.

// Find the minimum number of operations that will be required to make the graph connected.

// If it is not possible to make the graph connected, return -1.

// Example 1:

// Input: n = 6, edges = [[1,2],[2,3],[4,5],[5,6]]
// Output: 2
// Explanation: Remove edge (1,2) and add it between vertices 1 and 3.
// Example 2:

// Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: 1
// Explanation: Remove edge (1,5) and add it between vertices 1 and 3.
// Example 3:

// Input: n = 5, edges = [[1,2],[2,3],[3,4],[1,3],[1,4]]
// Output: 0
// Explanation: The graph is already connected.
// Example 4:

// Input: n = 4, edges = [[1,2],[2,3],[3,4],[4,1]]
// Output: -1
// Explanation: There is no way to connect the graph.

// Constraints:

// 1 <= n <= 10^5
// 1 <= m <= 3 * 10^4
// edges[i].length == 2
// 1 <= edges[i][0], edges[i][1] <= n
// edges[i][0] != edges[i][1]
// There are no duplicate edges.
// There are no self edges.
// The graph is connected.

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;
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

int Solve(int n, vector<vector<int>> &edge)
{
    DisjointSet ds(n);
    int cntExtras = 0;
    for (auto it : edge)
    {
        int u = it[0];
        int v = it[1];
        if (ds.findUPar(u) == ds.findUPar(v))
        {
            cntExtras++;
        }
        else
        {
            ds.unionBySize(u, v);
        }
    }
    int cntC = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.parent[i] == i)
            cntC++;
    }
    int ans = cntC - 1;
    if (cntExtras >= ans)
        return ans;
    return -1;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 5}, {5, 6}};
    cout << Solve(n, edges) << endl;
    return 0;
}