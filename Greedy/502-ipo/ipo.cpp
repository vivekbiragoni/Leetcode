class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();
        vector<pair<int, int>> projects(n);

        // Pairing projects with (capital, profit) and sorting by capital
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());

        // Max-heap for profits
        priority_queue<int> maxHeap;
        int j = 0;

        // Iterate k times to select at most k projects
        for (int i = 0; i < k; ++i) {
            // Add all projects that can be started with the current capital to
            // the max-heap
            while (j < n && projects[j].first <= w) {
                maxHeap.push(projects[j].second);
                ++j;
            }

            // If the max-heap is not empty, take the project with the max
            // profit
            if (!maxHeap.empty()) {
                w += maxHeap.top();
                maxHeap.pop();
            } else {
                break;
            }
        }

        return w;
    }
};