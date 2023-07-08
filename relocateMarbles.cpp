class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> ans;
        for(int i=0; i<nums.size(); i++){
            ans.insert(nums[i]);
        }
        for(int i=0; i<moveFrom.size(); i++){
            ans.erase(moveFrom[i]);
            ans.insert(moveTo[i]);
        }
        vector<int> res;
        for(auto it : ans){
            res.push_back(it);
        }
        return res;
    }
};
