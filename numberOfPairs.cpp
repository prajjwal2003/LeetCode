#include <unordered_map>
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int pairs = 0;
        int left = 0;
        for(auto i : m){
            if(i.second % 2 == 0){
                pairs+= i.second/2;
            }
            else{
                left++;
                pairs+= i.second/2;
            }
        }
        vector<int> ans(2); 
        ans[0] = pairs;
        ans[1] = left;
        return ans;
    }
};