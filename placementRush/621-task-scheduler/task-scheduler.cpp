class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int cont = 0;
        for(auto task: tasks){
            mp[task]++;
            cont = max(cont,mp[task]);
        }

        int ans  = (cont-1) * (n+1);

        for(auto task : mp){
            if(task.second==cont) ans++;
        }
        
        return max((int)tasks.size(), ans);

    }
};