class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return *max_element(nums.begin(), nums.end());
        }

        int i=2;
        while(i < n){
            nums[i]= nums[i] + *max_element(nums.begin(), nums.begin() + i-1);
            i++;
            continue;
        }
        return *max_element(nums.begin(), nums.end());
    }
};