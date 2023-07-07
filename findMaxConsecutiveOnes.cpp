class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, ans=0, count=0;
        while(i<nums.size()){
            if(nums[i]==1){
                count++;
                ans = max(ans, count);
                i++;
                continue;
            }
            count = 0;
            i++;
        }
        return ans;
    }
};
