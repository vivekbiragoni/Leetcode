class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<vector<pair<int, int>>> adj(n+1);
        for (auto time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int edgewt = it.second;
                int adjnode = it.first;

                if (dis + edgewt < dist[adjnode]) {
                    dist[adjnode] = dis + edgewt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());
        if (ans == 1e9)
            return -1;
        return ans;
    }
};