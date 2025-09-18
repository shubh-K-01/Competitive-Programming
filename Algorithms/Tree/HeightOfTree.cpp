#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> t[N];

// ---------- Debugging ----------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << nline;
#else
#define debug(x)
#endif

/**
 * Since we are working with trees, we can use a recursive approach to find the height of the tree.
 * We don't need visited vector to track/keep the data(isVisisted) of the node because the tree does'nt have a cycle.
 * The only point is to do not go back to the parent node, we can achieve this by checking if the child node is equal to the parent node.
 *
 * Time Complexity:
 * - Accessing neighbors: O(E), where E is the number of edges
 * - Storing the graph: O(N + E)
 * 
 * Space Complexity:
 * - O(N + E)
 * 
 */  

int height[N];
int depth[N];

void dfs(int vertex, int parent = 0) {
    /**
        Step 1: Take action on vertex after entering the vertex 
        ie: 
    **/

    for(int child : t[vertex]) {
        /**
            Step 2: Take action on child before entering the child node
            ie: 
        **/
       if(child == parent) continue;

        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);

        height[vertex] = max(height[vertex], height[child] + 1);

        /**
            Step 3: Take action on child after exiting the child node 
        **/
    }
        /**
            Step 4: Take action on vertex before exiting the vertex
        **/
}

// ---------- Main ----------
int32_t main() {

    int vert, ed;
    cin >> vert >> ed;

    for(int i = 0; i < ed; i++) {
        int vt1, vt2;
        cin >> vt1 >> vt2;

        t[vt1].push_back(vt2);
        t[vt2].push_back(vt1);
    }

    dfs(1); // Calling the dfs function for the root node

    return 0;
}
