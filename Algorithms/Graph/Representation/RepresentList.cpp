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

/**
 * Adjacency List
 * This approach is suited for questions where the size of the graph is >= 10^2
 * In this approach we use a vector of vectors to store the graph.
 * 
 * Where each vector stores the vertices which are connected to the given vertex.
 * This approach is more memory efficient than the Adjacency Matrix.
 * Total complexity of this approach is O(V + E) where V is the number of vertices and E is the number of edges.
 */

 // Initialize the graph with the number of vertices, The advantage of initializing the graph here is that we don't have to initialize the graph with 0. 
const int N = 1e3 + 10;
vector<int> adjList[N];

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

        // Add the edges to the adjacency list;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);

    }
    return 0;
}

/**
 * This approach is suited for questions where the size of the graph is large, typically N >= 10^3.
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
 * Example:
 * Suppose N = 10^5 and E = 2 * 10^5 (sparse graph)
 * 
 * Space Complexity: O(10^5 + 2 * 10^5) = O(3 * 10^5)
 * This is feasible compared to O(10^10) required for an adjacency matrix.
 * 
 * Adjacency List is preferred when:
 * - The graph is sparse (number of edges much smaller than N^2)
 * - We need to store large graphs without running into memory issues
 * - We want to efficiently iterate over neighbors of a node
 */
