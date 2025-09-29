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


vector<int> visited(N, 0);

bool dfs(int vertex, vector<int> &currentPath, vector<int> graph[]) {
    visited[vertex] = 1;
    currentPath[vertex] = 1;

    for(int nbr : graph[vertex]) { 
        if(!visited[nbr]) {
            int res = dfs(nbr, currentPath, graph);
            if(res) return true;
        } else {
            if(currentPath[nbr] == 1) {
                return true;
            }
        }
    }

    currentPath[vertex] = 0; // Backtrack (remove the vertex from the current path as the path is changed and node is no longer part of the current path but visited)
    return false;
}

bool isCycle(vector<int> graph[]) {
    vector<int> currentPath(N, 0), visited(N, 0);
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            if(dfs(i, currentPath, graph)) return true;
        }
    }
    return false;
}

/**
 * This algorithm detects whether a directed graph contains a cycle or not.
 * The algorithm uses Depth First Search (DFS) to traverse the graph and keep track of the current path.
 * For this purpose, we use a visited array and a current path array. Current path array is used to keep track of the nodes that are part of the current path.
 * If at any point we find a visited node which is part of the current path, then we have found a cycle.
 * The algorithm starts from each unvisited node and performs DFS.
 * If a cycle is found, the function returns true, otherwise it returns false.
 * 
 * Time Complexity: O(N + E), where N is the number of vertices and E is the number of edges.
 * Space Complexity: O(N), to store the visited array and the current path.
 */