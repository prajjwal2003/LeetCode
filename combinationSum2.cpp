class Solution {
public: 
    void combinationSum2(vector<int>& candidates, int target, vector<vector<int>> &output, vector<int> &temp, int index){
        if(target<0){
            return;
        }
        if(target==0){
            output.push_back(temp);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            combinationSum2(candidates, target-candidates[i], output, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        vector<int> temp;
        combinationSum2(candidates, target, output, temp, 0);
        return output;
    }
};