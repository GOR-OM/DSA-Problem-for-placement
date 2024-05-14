// You are given an n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.

// You can change at most one cell in grid from 0 to 1.

// You need to find the largest group of connected  1's.

// Two cells are said to be connected if both are adjacent to each other and both have same value.

// Example 1:

// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: You can change one 0 to 1 and connect the one's together:
// [[1,1],[1,1]]
// The largest group of connected 1's has four cells.
// Example 2:

// Input: grid = [[1,0],[0,1]]
// Output: 3
// Example 3:

// Input: grid = [[1,1],[1,1]]
// Output: 4

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

bool isValid(int newr, int newc, int n)
{
    return newr >= 0 && newr < n && newc >= 0 && newc < n;
}

int MaxConnection(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjointSet ds(n * n);
    // step - 1
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for (int ind = 0; ind < 4; ind++)
            {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                {
                    int nodeNo = row * n + col;
                    int adjNodeNo = newr * n + newc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }
    // step 2
    int mx = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 1)
                continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            set<int> components;
            for (int ind = 0; ind < 4; ind++)
            {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (isValid(newr, newc, n))
                {
                    if (grid[newr][newc] == 1)
                    {
                        components.insert(ds.findUPar(newr * n + newc));
                    }
                }
            }
            int sizeTotal = 0;
            for (auto it : components)
            {
                sizeTotal += ds.size[it];
            }
            mx = max(mx, sizeTotal + 1);
        }
    }
    for (int cellNo = 0; cellNo < n * n; cellNo++)
    {
        mx = max(mx, ds.size[ds.findUPar(cellNo)]);
    }
    return mx;
}

int main(){
   vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0}
    };

    int ans = MaxConnection(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
    return 0;
}