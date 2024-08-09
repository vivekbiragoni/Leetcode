### Explanation of the `topoSort` Function

This code implements the topological sort of a directed acyclic graph (DAG). Topological sorting is a linear ordering of vertices such that for every directed edge `u -> v`, vertex `u` comes before `v` in the ordering.

#### 1. **DFS-Based Topological Sorting**

- **Function: `dfs`**
  - **Purpose**: The `dfs` function performs a Depth-First Search (DFS) to explore all vertices of the graph. As each vertex finishes its exploration, it is pushed onto a stack.
  - **Parameters**:
    - `int node`: The current node being visited.
    - `int vis[]`: An array to mark nodes as visited.
    - `stack<int>& st`: A stack to store the topological order of vertices.
    - `vector<int> adj[]`: The adjacency list of the graph.
  - **Algorithm**:
    1. Mark the current node as visited (`vis[node] = 1`).
    2. For each neighbor of the current node, if the neighbor is unvisited, recursively call `dfs` on it.
    3. After exploring all neighbors, push the current node onto the stack (`st.push(node)`).
  
- **Function: `topoSort`**
  - **Purpose**: This function orchestrates the topological sort by calling `dfs` on all unvisited nodes and collecting the topological order in a vector.
  - **Parameters**:
    - `int V`: The number of vertices in the graph.
    - `vector<int> adj[]`: The adjacency list of the graph.
  - **Algorithm**:
    1. **Initialization**:
       - `int vis[V] = {0}`: An array to track visited nodes, initialized to `0` (unvisited).
       - `stack<int> st`: A stack to store the vertices in topological order.
    2. **DFS Execution**:
       - For each node `i` from `0` to `V-1`, if the node is unvisited, call `dfs` on it.
    3. **Collect Topological Order**:
       - Pop all elements from the stack and store them in a vector `ans`, which represents the topological order.
    4. **Return**: The vector `ans` containing the vertices in topological order is returned.

#### 2. **Function: `check`**

- **Purpose**: This function verifies if the topological sort returned by the `topoSort` function is correct.
- **Parameters**:
  - `int V`: The number of vertices in the graph.
  - `vector<int>& res`: The result of the topological sort.
  - `vector<int> adj[]`: The adjacency list of the graph.
- **Algorithm**:
  1. **Map Creation**: Create a mapping of vertices to their positions in the topological order.
  2. **Validation**: For each vertex `i` and its neighbor `v`, check if `i` appears before `v` in the topological order. If any vertex appears after its neighbor, return `0` (indicating an incorrect sort).
  3. **Return**: Return `1` if the topological sort is valid, otherwise return `0`.

### Key Concepts

- **Topological Sorting**: This algorithm produces a linear order of vertices in a graph, where for any directed edge `u -> v`, vertex `u` appears before vertex `v`.
- **Depth-First Search (DFS)**: The algorithm relies on DFS to explore each vertex and its neighbors. Vertices are pushed onto the stack as they finish their DFS exploration.
- **Stack-Based Approach**: By using a stack, the algorithm ensures that vertices with no outgoing edges (or already visited vertices) are placed last in the order, which aligns with the requirements of topological sorting.

### Example Walkthrough

For a graph represented by `adj = [[1, 2], [2], []]`:
- Node `0` has outgoing edges to `1` and `2`.
- Node `1` has an outgoing edge to `2`.
- Node `2` has no outgoing edges.
  
**DFS Order**:
1. Start at node `0`, visit `1`, then visit `2`.
2. Push `2` to the stack, then `1`, and finally `0`.
3. The resulting topological order is `[0, 1, 2]`.

### Important Notes

- **Applicability**: Topological sorting only applies to directed acyclic graphs (DAGs). If the graph contains a cycle, a topological sort is impossible.
- **Efficiency**: The time complexity of this algorithm is `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges, making it efficient for typical graph problems.
- **Space Complexity**: The space complexity is `O(V)` due to the stack and visitation arrays used.

This approach ensures that all vertices are sorted in a way that respects the directed edges of the graph, making it a crucial algorithm in scenarios like task scheduling, resolving dependencies, etc.
