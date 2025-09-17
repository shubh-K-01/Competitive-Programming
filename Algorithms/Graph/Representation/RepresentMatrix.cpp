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

// ---------- Main ----------
int32_t main() {

    /**
     * Given n = total number of vertices in the graph
     * m = total number of edges in the graph;
     */
    int n,m;
    cin >> n >> m;

    // Matrix with 1 based indexing;
    int graph[n+1][n+1] = {0};

    /**
     * Loop for all the edges present in the graph
     */
    for(int i = 0; i < m; i++) {

        // Input of two vertices which are connected by this edge;
        int v1, v2;
        cin >> v1 >> v2;

        /**
           *  Connect the vertices with the given edge (Kepping for undirected graph.
           *  If directed graph is given, either one of the statment is needed to connect the vertices)
        **/

        graph[v1][v2] = 1;
        graph[v2][v1] = 1; 

    }
    return 0;
}

/**
 * This approach is suited for questions where the size of the graph is <= 10^2
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * 
 * Suppose N = 10^5
 * 
 * Time Complexity: O(10^5 * 10^5) = O(10^10)
 * Space Complexity: O(10^5 * 10^5) = O(10^10)
 * 
 * This noticeable increase in the time and space complexity.
 * Even if the graph is of size 10^3, the time complexity will be O(10^6) and space complexity will be O(10^6)
 * We cannot store the graph in a matrix of size 10^3.
 * Hence the approach more suited for questions where the size of the graph is >= 10^3 is the Adjacency List.
 */
