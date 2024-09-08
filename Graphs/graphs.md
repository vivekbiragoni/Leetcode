
### 1. **Breadth-First Search (BFS)**
   - **Purpose**: Explore all vertices level by level in an unweighted graph.
   - **Steps**:
     1. Start from a source node `s`.
     2. Use a queue to explore all neighboring nodes.
     3. Mark nodes as visited to avoid revisits.

```cpp
vector<int> bfs(vector<vector<int>> &adj, int s, vector<bool> &visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    vector<int> ans;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        ans.push_back(ele);
        for(auto ad: adj[ele]){
            if(!visited[ad]){
                visited[ad] = true;
                q.push(ad);
            }
        }
    }
    return ans;
}
```

### 2. **Depth-First Search (DFS)**
   - **Purpose**: Explore as far as possible along each branch before backtracking.
   - **Steps**:
     1. Start from a node, mark it as visited.
     2. Recursively explore all unvisited neighboring nodes.

```cpp
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for(auto nextNode: adj[node]){
        if(!visited[nextNode]){
            dfs(nextNode, adj, visited);
        }
    }
}
```

### 3. **Dijkstra's Algorithm**
   - **Purpose**: Find the shortest path from a source node to all other nodes in a graph with non-negative weights.
   - **Steps**:
     1. Use a priority queue (min-heap) to always expand the node with the shortest known distance.
     2. Update the distances of neighboring nodes if a shorter path is found.

```cpp
vector<int> dijkstra(int source, vector<vector<pair<int, int>>> &adj, int V) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]) {
            int edgewt = it.second;
            int adjNode = it.first;

            if(dis + edgewt < dist[adjNode]) {
                dist[adjNode] = dis + edgewt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
```

### 4. **Topological Sort (DFS-based)**
   - **Purpose**: Linear ordering of vertices in a Directed Acyclic Graph (DAG).
   - **Steps**:
     1. Perform DFS, pushing nodes to a stack after all their dependencies are explored.
     2. Pop nodes from the stack to get the topological order.

```cpp
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for(auto nextNode: adj[node]){
        if(!visited[nextNode]){
            dfs(nextNode, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(int V, vector<vector<int>> &adj) {
    stack<int> st;
    vector<bool> visited(V, false);
    for(int i = 0; i< V; i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
```


### Detecting Cycles in Directed Graphs (DFS-based approach)

**Key Concept**: Use Depth First Search (DFS) with two arrays: 
- **visited**: Tracks whether a node has been visited.
- **instack**: Tracks whether a node is part of the current recursion stack.

**Pattern**:
1. Traverse the graph using DFS.
2. If you encounter an unvisited node, recursively call DFS on its neighbors.
3. If a neighbor is part of the current recursion stack (`instack`), a cycle is detected.
4. Once a node's DFS is complete, remove it from the recursion stack.
5. If no back edge is found during DFS, push the node onto a stack to store topological order.

```cpp
bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int>& st, vector<bool> &instack){
    visited[node] = true;
    instack[node] = true;  // Mark the node as in the current recursion stack

    for (auto adjNode: adj[node]) {
        if (!visited[adjNode]) {
            if (!dfs(adjNode, adj, visited, st, instack)) {
                return false;  // Cycle detected
            }
        } else if (instack[adjNode]) {
            return false;  // Back edge found, cycle exists
        }
    }

    instack[node] = false;  // Remove from the recursion stack
    st.push(node);  // Push node for topological sorting
    return true;
}
```

**Use Cases**:
- Frequently used in questions involving detecting cycles in directed graphs.
- Key component of algorithms like Topological Sorting and Dependency Resolution.


### 5. **Cycle Detection (DFS-based)**
   - **Purpose**: Detect a cycle in an undirected graph using DFS.
   - **Steps**:
     1. If a visited node is encountered that isn’t the parent of the current node, a cycle exists.

```cpp
bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for(auto nextNode: adj[node]) {
        if(!visited[nextNode]) {
            if(dfs(nextNode, node, adj, visited)) return true;
        } else if(nextNode != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++) {
        if(!visited[i] && dfs(i, -1, adj, visited)) return true;
    }
    return false;
}
```

### 6. **Bellman-Ford Algorithm**
   - **Purpose**: Compute shortest paths from a single source to all other vertices, even with negative edge weights.
   - **Steps**:
     1. Relax all edges `V-1` times.
     2. Check for negative cycles by verifying if another relaxation is possible.

```cpp
vector<int> bellmanFord(int source, int V, vector<vector<int>> &edges) {
    vector<int> dist(V, 1e9);
    dist[source] = 0;

    for (int i = 1; i < V; i++) {
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            cout << "Graph has a negative cycle" << endl;
            return {};
        }
    }
    return dist;
}
```

### 7. **Floyd-Warshall Algorithm**
   - **Purpose**: Find shortest paths between all pairs of nodes.
   - **Steps**:
     1. Use dynamic programming to iteratively improve paths between all pairs.
     2. Detect negative cycles by checking the diagonal of the matrix.

```cpp
vector<vector<int>> floydWarshall(int V, vector<vector<int>> &graph) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Graph has a negative cycle" << endl;
            return {};
        }
    }
    return dist;
}
```

### 8. **Prim's Algorithm (Minimum Spanning Tree)**
   - **Purpose**: Find the MST of a graph.
   - **Steps**:
     1. Use a priority queue to always pick the smallest edge connecting a node to the MST.

```cpp
vector<pair<int, int>> primMST(int V, vector<vector<pair<int, int>>> &adj) {
    vector<int> key(V, 1e9), parent(V, -1);
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if (!visited[adjNode] && weight < key[adjNode]) {
                key[adjNode] = weight;
                pq.push({key[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    vector<pair<int, int>> mst;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            mst.push_back({parent[i], i});
        }
    }
    return mst;
}
```

### 9. **Kruskal's Algorithm (Minimum Spanning Tree)**
   - **Purpose**: Find the MST using Disjoint Set Union (DSU).
   - **Steps**:
     1. Sort all edges.
     2. Add the smallest edge to the MST, ensuring it doesn't form a cycle (using DSU).

```cpp
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        size

.resize(n+1, 1);
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV) return;

        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
};

int kruskalMST(int V, vector<vector<int>> &edges) {
    DisjointSet ds(V);
    sort(edges.begin(), edges.end());
    int mstWeight = 0;

    for (auto &edge : edges) {
        int weight = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (ds.findParent(u) != ds.findParent(v)) {
            mstWeight += weight;
            ds.unionBySize(u, v);
        }
    }
    return mstWeight;
}
```

### 10. **Kosaraju's Algorithm (Strongly Connected Components)**
   - **Purpose**: Identify all Strongly Connected Components (SCCs) in a directed graph.
   - **Steps**:
     1. Perform DFS on the original graph, filling a stack based on finish times.
     2. Reverse the graph.
     3. Perform DFS on the reversed graph, processing nodes in stack order.

```cpp
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (auto adjNode : adj[node]) {
        if (!visited[adjNode]) {
            dfs(adjNode, adj, visited, st);
        }
    }
    st.push(node);
}

void dfsT(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);
    for (auto adjNode : adj[node]) {
        if (!visited[adjNode]) {
            dfsT(adjNode, adj, visited, component);
        }
    }
}

vector<vector<int>> kosarajuSCC(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<vector<int>> adjT(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            vector<int> component;
            dfsT(node, adjT, visited, component);
            sccs.push_back(component);
        }
    }
    return sccs;
}
```
