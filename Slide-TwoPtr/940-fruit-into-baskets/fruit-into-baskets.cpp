class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size(); 
        int left = 0 ;
        int maxFruits = 0;
        unordered_map<int, int> fruitsCount;

        for(int right = 0; right < n; right++){
            fruitsCount[fruits[right]]++; 

            if(fruitsCount.size()>2){
                fruitsCount[fruits[left]]--;

                if(fruitsCount[fruits[left]]==0){
                    fruitsCount.erase(fruits[left]);
                } 
                left++;
            }
            if(fruitsCount.size()<=2){
                maxFruits = max(maxFruits, right -left + 1);
            }
            
        }
        return maxFruits ;
    }
};