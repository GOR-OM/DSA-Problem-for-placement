#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>> moves={
    {1,0},{0,1},{-1,0},{0,-1}
};

void dfs(int i, int j, int k, vector<vector<int>>& ans, int color){
    int n = ans.size();
    int m = ans[0].size();
    
    if(i < 0 || j < 0 || i >= n || j >= m || ans[i][j] != k) {
        return;  // Base case: out of bounds or not matching color
    }
    
    ans[i][j] = color;

    for(auto child : moves){
        int p_x = i + child.first;
        int p_y = j + child.second;

        dfs(p_x, p_y, k, ans, color);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int k = image[sr][sc];
    if (k != color) {
        dfs(sr, sc, k, image, color);
    }
    return image;    
}