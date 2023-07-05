class Compare{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto it : m){
            pq.push({it.second, it.first});
        }
        while(!pq.empty()){
            pair<int, int> temp = pq.top();
            while(temp.first--){
                ans.push_back(temp.second);
            }
            pq.pop();
        }
        return ans;
    }
};
