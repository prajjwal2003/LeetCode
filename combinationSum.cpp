class Solution {
public:
    vector<vector<int>> res;
    void helper(int i, vector<int>& candidates, int target, int sum, vector<int>& temp){
        if(sum > target){
            return;
        }
        if(i==candidates.size()){
            if(sum==target){
                res.push_back(temp);
            }
            return;
        }
        helper(i+1, candidates, target, sum, temp);
        sum+= candidates[i];
        temp.push_back(candidates[i]);
        helper(i, candidates, target, sum, temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(0, candidates, target, 0, temp);
        return res;
    }
};