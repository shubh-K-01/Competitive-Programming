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

void dfs(int vertex) {
    /**
        Step 1: Take action on vertex after entering the vertex 
        ie: 
    **/
    visited[vertex] = 1;
    for(auto child : graph[vertex]) {
        if(visited[child]) continue;
         /**
            Step 2: Take action on child after entering the child node 
            ie: 
        **/
        dfs(child);

         /**
            Step 3: Take action on child after exiting the child node 
            ie: 
        **/
    }
     /**
        Step 4: Take action on vertex before exiting the vertex  
        ie: 
    **/

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

    int connected = 0;

    for(int i = 1; i <=n; ++i) {
        if(visited[i]) continue;

        dfs(i);
        connected++;
    }

    cout << connected;
    return 0;
}

/**
 * This method let's us find the number of connected components in the graph by using Depth First Search Algorithm. 
 * Step 1 : Take a visited vector to track/keep the data(isVisisted) of the node  
 * Step 2 : Start the dfs function from a particular node to find the connected components in the graph. 
 * Step 3 : Increment the connected variable by 1 when the dfs function is called.
 * 
 * Adjacency List is preferred when:
 * - The graph is sparse (number of edges much smaller than N^2)
 * - We need to store large graphs without running into memory issues
 * - We want to efficiently iterate over neighbors of a node
 * 
 * Compared to an adjacency matrix, an adjacency list is much more space-efficient, especially for sparse graphs.
 * 
 * Time Complexity:
 * - Accessing neighbors: O(E), where E is the number of edges
 * - Storing the graph: O(N + E)
 * 
 * Space Complexity:
 * - O(N + E)
 * 
 */