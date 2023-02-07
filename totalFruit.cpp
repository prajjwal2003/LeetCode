#include <unordered_map>
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int left = 0;
        int count = 0;
        int ans = 0;
        for(int i=0; i<fruits.size(); i++){
            m[fruits[i]]++;
            while(m.size() > 2){
                m[fruits[left]]--;
                if(m[fruits[left]] == 0){
                    m.erase(fruits[left]);
                }
                left++;
            }
            count = i-left+1;
            ans = max(ans, count);
        }
        return ans;
    }
};