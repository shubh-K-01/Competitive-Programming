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
 * TOPOLOGICAL SORT with BFS (Kahn's Algorithm)
 * Idea behind the algo : Any node which has no indegree (ie: 0 incoming edges) will be visited first.
 * Every dependent node of a node is to be visited first before the node.
 * After every non dependent node is visited, every dependent node of that non dependent node will become non dependent.
 * 
 * 0 dependent nodes => 0 dependency => 0 prerequisites
 * 
 * Step 1 : Push all the nodes with 0 dependency/on level 1 into a queue and mark them as visited.
 * Step 2 : Remove the node from the queue and reduce the indegree(dependency edge) of all its dependent nodes by 1.
 * Step 3 : If the indegree of any dependent node is 0, then push it into the queue and mark it as visited. 
 * 
 * Time Complexity:
 * - Accessing neighbors: O(E), where E is the number of edges
 * - Storing the graph: O(N + E)
 * 
 * Space Complexity:
 * - O(N + E)
 * 
 */
class KahnsAlgorithm {
public:
    vector<int> topologicalSortBFS(vector<vector<int>> &graph) {
    int size = graph.size();

    vector<int> inDegree(size, 0);
    vector<int> sortedOrder;
    queue<int> q;

    for(int i = 0; i < size; i++) {
        for(int &child : graph[i]) {
            inDegree[child]++;
        }
    }

    for(int i = 0; i < size; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int first = q.front();
        q.pop();
        sortedOrder.push_back(first);

        for(int &child : graph[first]) {
            if(--inDegree[child] == 0) {
                q.push(child);
            }
        }
    }
    return sortedOrder;
}
};

/**
 * TOPOLOGICAL SORT with DFS
 * 
 * Idea behind the algo:
 * Topological sorting can also be achieved using Depth-First Search (DFS).
 * The key idea is that for every directed edge U -> V, 
 * node U must come before node V in the ordering.
 * 
 * DFS ensures this by:
 * 1. Visiting the depth-first neighbors of a node first.
 * 2. Once all dependencies (depth-first neighbors) of a node are fully explored, 
 *    the node itself is pushed onto a Deque/ at the front (Just before returning from the end node of the path).
 * 
 * In this algorithm, it's not necessary that dfs will be applied only once. DFS might be called 
 * 
 * Step 1 : Initialize all nodes as unvisited.
 * Step 2 : Perform DFS on each unvisited node.
 * Step 3 : During DFS, recursively visit all neighbors (dependencies).
 * Step 4 : After visiting all neighbors of a node, push it to a stack (post-order).
 * Step 5 : At the end, pop elements from the stack to get the topological ordering.
 * 
 * Time Complexity:
 * - Visiting all nodes + edges in DFS: O(N + E), 
 *   where N = number of vertices, E = number of edges.
 * 
 * Space Complexity:
 * - O(N + E) for recursion stack and adjacency list.
 * - O(N) extra for visited array and stack.
 * 
 * Notes:
 * - Works only for Directed Acyclic Graphs (DAG).
 * - If a cycle exists, topological sort is not possible.
 */

class TopologicalDFS{
public:

    deque<int> dq;
    void dfs(int node, vector<int> &visited, vector<vector<int>> &graph) {
        visited[node] = 1;
        for(int &child : graph[node]) {
            if(!visited[child]) {
                dfs(child, visited, graph);
            }
        }
        dq.push_back(node);
    }

    vector<int> topologicalSortDFS(vector<vector<int>> &graph) {
        int size = graph.size();

        vector<int> visited(size, 0);
        for(int i = 0; i < size; i++) {
            if(!visited[i]) {
                dfs(i, visited, graph);
            }
        }

        vector<int> ans;
        for(auto it : dq) {
            ans.push_back(it);
        }
        return ans;
    }
};



/**
 * topological Sort (Sorting Algo) is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every edge u -> v, u comes before v in the ordering.
 * This type of sort only works for DAGs. DAG = Directed Acyclic Graph
 * 
 * DAG or Topological Sort simpley refers to a graph with no cycles.
 * It states that traverse the nodes in a particular order where nodes with no predecessors are traversed first.
 * 
 * Topological Sort is implemented using DFS which is a backtracking algorithm.
 * Other way to implement a topological sort is with BFS using Kahn's Algorithm.
 * 
 */