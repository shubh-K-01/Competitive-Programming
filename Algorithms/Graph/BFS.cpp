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
vector<int> level(N, 0);

void bfs(int source) {

    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()) {
        int curr_v = q.front();
        q.pop();

        for(int child : graph[curr_v]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = 1;
                level[child] = level[curr_v] + 1;
            }
        }
    }

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

    bfs(1);

    for(int i = 1; i <= vert; i++) {
        cout << i << " : " << level[i] << " ";
    }   

    return 0;
}

/**
 * In BFS, the traversal is done in the level order. At every level we visit all the nodes present in that level.
 * Every vertice is visited and then its children are visited at the next level. 
 * In this fashion, every vertices is visited and processed. As we visit anything first time then do the processing. This reminds of a queue.
 * So the flow of the code is :
 * 1. Visit the vertex
 * 2. Put it in the queue
 * 3. Make it visited in the visited array
 * 4. Pop the queue. 
 * 5. Visit its children
 * 
 * Thye time complexity of BFS is O(N + E), where N is the number of vertices and E is the number of edges.
 * The while loop will run for the number of vertices present which will be pushed in the queue. and everytime pop out.
 * This will continue for all the vertices of the same level(vertex which is pushed).
 */
