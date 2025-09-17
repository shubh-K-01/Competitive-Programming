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
bool isLoop = false;

bool dfs(int vertex, int parent) {

    visited[vertex] = 1;
    for(auto child : graph[vertex]) {
        if(visited[child] && child == parent) continue;
        if(visited[child]) return true; 

        isLoop |= dfs(child, vertex);
    }

    return isLoop;
}

// ---------- Main ----------
int32_t main() {

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1, v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bool isLoopExist = false;

    for(int i = 1; i <=n; ++i) {
        if(visited[i]) continue;
        if(dfs(i, -1)) {
            isLoopExist = true;
            break;
        }
    }

    cout << isLoopExist;
    return 0;
}

/**
 * This method let's us find the number of connected components in the graph by using Depth First Search Algorithm. 
 * Step 1 : Take a visited vector to track/keep the data(isVisisted) of the node  
 * Step 2 : Start the dfs function from a particular node to find the connected components in the graph. 
 * Step 3 : Increment the connected variable by 1 when the dfs function is called.
 * 
 */