class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, i=0, start=0;
        while(i<nums.size() && nums[i]==1){
            i++;
        }
        if(i==nums.size()){
            return nums.size()-1;
        }
        int zeroIndex = i++;
        while(i<nums.size()){
            if(nums[i]==1){
                i++;
                continue;
            }
            ans = max(ans, i-start-1);
            start = zeroIndex + 1;
            zeroIndex = i;
            i++;
        }
        ans = max(ans, i-start-1);
        return ans;
    }
};
