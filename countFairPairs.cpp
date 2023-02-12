class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            int small = lower - nums[i];
            int big = upper - nums[i];
            auto left = lower_bound(nums.begin()+i+1, nums.end(), small);
            auto right = upper_bound(nums.begin()+i+1, nums.end(), big);
            ans+= right-left;
        }
        return ans;
    }
};