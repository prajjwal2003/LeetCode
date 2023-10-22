class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        int lmin = nums[0];
        int rmin = nums[nums.size()-1];
        for(int i=1; i<nums.size()-1; i++){
            left[i] = min(lmin, nums[i-1]);
            lmin = left[i];
        }
        for(int i=nums.size()-2; i>0; i--){
            right[i] = min(rmin, nums[i+1]);
            rmin = right[i];
        }
        bool flag = false;
        int ans = INT_MAX;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] > left[i] && nums[i] > right[i]){
                flag = true;
                ans = min(ans, nums[i]+left[i]+right[i]);
            }
        }
        if(flag)return ans;
        return -1;
    }
};
