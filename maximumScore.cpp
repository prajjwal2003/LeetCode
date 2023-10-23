class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k], len = 1, i = k-1, j = k+1, mini = nums[k];
        while(i>=0 || j<nums.size()){
            len++;
            if(i<0){
                mini = min(mini, nums[j]);
                ans = max(ans, len*mini);
                j++;
                continue;
            }
            else if(j>=nums.size()){
                mini = min(mini, nums[i]);
                ans = max(ans, len*mini);
                i--;
                continue;
            }
            else{
                if(nums[i] >= nums[j]){
                    mini = min(mini, nums[i]);
                    i--;
                }
                else{
                    mini = min(mini, nums[j]);
                    j++;
                }
                ans = max(ans, len*mini);
            }
        }
        return ans;
    }
};
