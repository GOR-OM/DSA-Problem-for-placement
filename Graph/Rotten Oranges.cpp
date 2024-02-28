#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // Directions for adjacent cells
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Queue to store rotten oranges
    queue<pair<int, int>> q;

    // Count of fresh oranges
    int freshCount = 0;

    // Initialize the queue and count the fresh oranges
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                freshCount++;
            }
        }
    }

    // If there are no fresh oranges, return 0
    if (freshCount == 0)
    {
        return 0;
    }

    int minutes = 0;

    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (auto dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                {
                    // Mark the fresh orange as rotten
                    grid[newX][newY] = 2;
                    q.push({newX, newY});
                    freshCount--;
                    flag = true;
                }
            }
        }

        if (flag)
        {
            minutes++;
        }
    }

    // If there are any remaining fresh oranges, return -1
    if (freshCount > 0)
    {
        return -1;
    }

    return minutes;
}