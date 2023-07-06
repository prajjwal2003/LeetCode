class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] %2 != 0 || nums[i] > threshold){
                i++;
                continue;
            }
            bool even = false;
            int j = i+1;
            while(j<nums.size()){
                if(nums[j] > threshold){
                    break;
                }
                if(even && nums[j]%2!=0){
                    break;
                }
                if(!even && nums[j]%2==0){
                    break;
                }
                j++;
                even = !even;
            }
            ans = max(ans, j-i);
            i = j;
        }
        return ans;
    }
};
