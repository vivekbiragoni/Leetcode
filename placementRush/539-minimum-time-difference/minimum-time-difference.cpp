class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> temp;
        for (auto t : timePoints) {
            int hr = stoi(t.substr(0, 2));
            int mn = stoi(t.substr(3, 2));
            int present = hr * 60 + mn;
            temp.push_back(present);
            cout << "present" << present << endl;
        }
        sort(temp.begin(), temp.end());
        int mini = 1e9;
        for (int i = 1; i < n; i++) {
            mini = min(mini, abs(temp[i] - temp[i - 1]));
        }
            mini = min(mini, abs(1440 - (temp[n - 1] - temp[0])));
        
        return mini;
    }
};