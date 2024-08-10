### Notes for Shortest Path in Directed Acyclic Graph (DAG)

#### Problem Overview:
- **Objective:** Find the shortest path from a starting node (node 0) to all other nodes in a directed acyclic graph (DAG).
- **Approach:** Use Topological Sorting followed by Distance Relaxation.

#### Key Concepts:

1. **Adjacency List Construction:**
   - The graph is represented as an adjacency list where each node has a list of its neighboring nodes along with the weights of the edges.

   ```cpp
   vector<pair<int, int>> adj[N];
   for(int i = 0; i < M; i++){
       int u = edges[i][0];
       int v = edges[i][1];
       int wt = edges[i][2];
       adj[u].push_back({v, wt});
   }
   ```

2. **Topological Sort:**
   - **Purpose:** To process nodes in an order that respects their dependencies.
   - **DFS Approach:** Traverse the graph using DFS, and push nodes onto a stack once all their descendants have been visited.
   - **Stack:** The nodes in the stack represent the topologically sorted order.

   ```cpp
   void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int> &st){
       vis[node] = 1;
       for(auto it: adj[node]){
           int v = it.first;
           if(!vis[v]){
               topoSort(v, adj, vis, st);
           }
       }
       st.push(node);
   }
   ```

3. **Distance Initialization:**
   - Initialize the distance to all nodes as infinity (`1e9`), except for the start node (`dist[0] = 0`).
   
   ```cpp
   vector<int> dist(N, 1e9);
   dist[0] = 0;
   ```

4. **Distance Relaxation:**
   - Process each node in the order defined by the topological sort.
   - For each node, update the distance to its neighbors if a shorter path is found.
   
   ```cpp
   while(!st.empty()){
       int node = st.top();
       st.pop();
       
       if(dist[node] != 1e9){
           for(auto it: adj[node]){
               int v = it.first;
               int wt = it.second;
               if(dist[node] + wt < dist[v]){
                   dist[v] = dist[node] + wt;
               }
           }
       }
   }
   ```

5. **Handle Unreachable Nodes:**
   - After processing, any node that still has the initial distance (`1e9`) is marked as unreachable (`-1`).

   ```cpp
   for(int i = 0; i < N; i++){
       if(dist[i] == 1e9){
           dist[i] = -1;
       }
   }
   ```

6. **Return the Distance Array:**
   - The final array contains the shortest distances from the start node to all other nodes, with `-1` indicating unreachable nodes.

   ```cpp
   return dist;
   ```

#### Complete Code:
```cpp
class Solution {
    private:
        void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int> &st){
            vis[node] = 1;
            for(auto it: adj[node]){
                int v = it.first;
                if(!vis[v]){
                    topoSort(v, adj, vis, st);
                }
            }
            st.push(node);
        }
    public:
        vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
            // Create the adjacency list
            vector<pair<int, int>> adj[N];
            for(int i = 0; i < M; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                adj[u].push_back({v, wt});
            }
            
            // Perform topological sort
            int vis[N] = {0};
            stack<int> st;
            for(int i = 0; i < N; i++){
                if(!vis[i]){
                    topoSort(i, adj, vis, st);
                }
            }
            
            // Initialize distances to infinity, except for the start node (assumed as node 0)
            vector<int> dist(N, 1e9);
            dist[0] = 0;
            
            // Relax distances according to topological order
            while(!st.empty()){
                int node = st.top();
                st.pop();
                
                if(dist[node] != 1e9){
                    for(auto it: adj[node]){
                        int v = it.first;
                        int wt = it.second;
                        if(dist[node] + wt < dist[v]){
                            dist[v] = dist[node] + wt;
                        }
                    }
                }
            }
            
            // Replace unreachable nodes' distances with -1
            for(int i = 0; i < N; i++){
                if(dist[i] == 1e9){
                    dist[i] = -1;
                }
            }
            
            return dist;
        }
};
```

#### Key Points to Remember:
- **Topological Sort** is crucial for correctly computing shortest paths in a DAG.
- **Distance Relaxation** only happens in the correct topological order.
- **Handling Unreachable Nodes** is important to avoid incorrect output.
