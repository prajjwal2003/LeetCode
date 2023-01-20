#include <unordered_map>
#include <queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto i=m.begin(); i!=m.end(); i++){
            pq.push({i->second, i->first});
        }
        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};