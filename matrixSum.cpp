class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(int i=0; i<nums.size(); i++){
            sort(nums[i].begin(), nums[i].end());
        }
        int score = 0;
        int i = nums[0].size()-1;
        while(i>=0){
            int maxi = 0;
            for(int j=0; j<nums.size(); j++){
                maxi = max(maxi, nums[j][i]);
            }
            score+= maxi;
            i--;
        }
        return score;
    }
};