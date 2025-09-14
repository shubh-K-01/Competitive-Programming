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

    int vert, ed;
    cin >> vert >> ed;

    for(int i = 0; i < ed; i++) {
        int vt1, vt2;
        cin >> vt1, vt2;

        graph[vt1].push_back(vt2);
        graph[vt2].push_back(vt1);
    }

    return 0;
}
