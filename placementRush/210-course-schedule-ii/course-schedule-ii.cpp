class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int>& st, vector<bool> &instack){
        visited[node]=true;
        instack[node]=true;
        for(auto adjNode: adj[node]){
            if(!visited[adjNode]){
                if(!dfs(adjNode, adj, visited, st, instack)){
                    return false;
                }
            }else if(instack[adjNode]){
                return false;
            }
        }
        instack[node]=false;
        st.push(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        stack<int> st;
        vector<bool>visited(numCourses, false), instack(numCourses, false);
        for(int i = 0; i< numCourses; i++){
            if(!visited[i]){
                if(!dfs(i, adj, visited, st, instack)){
                    return {};
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};