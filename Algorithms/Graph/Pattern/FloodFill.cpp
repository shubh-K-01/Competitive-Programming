#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];

// ---------- Debugging ----------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << nline;
#else
#define debug(x)
#endif

// Vector to track/keep the data(isVisisted) of the node  
vector<int> visited(N, 0);

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &gph) {

    int n = gph.size();
    int m = gph[0].size();

    if(i < 0 || j < 0) return;
    if(i >= n || j >= m) return;
    if(gph[i][j] != initialColor) return;

    gph[i][j] = newColor;

    dfs(i-1, j, initialColor, newColor, gph);
    dfs(i+1, j, initialColor, newColor, gph);
    dfs(i, j+1, initialColor, newColor, gph);
    dfs(i, j-1, initialColor, newColor, gph);
}


// ---------- Main ----------
vector<vector<int>> floodFill(vector<vector<int>>& gph, int sr, int sc, int color) {
    
    int initialColor = gph[sr][sc];
    if(initialColor != color) {
        dfs(sr, sc, initialColor, color, gph);
    }

    return gph;
}
