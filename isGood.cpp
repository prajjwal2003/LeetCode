class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = *max_element(nums.begin(), nums.end());
        if(n+1 != nums.size()){
            return false;
        }
        int count = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                count++;
            }
            if(count > 1){
                return false;
            }
        }
        return nums[nums.size()-1]==nums[nums.size()-2];
    }
};