class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int maxi = nums[nums.size()-1];
        int n = nums.size();
        if(n%2 != 0){
            if(nums[n/2] != mini && nums[n/2] != maxi){
                return nums[n/2];
            }
            else{
                return -1;
            }
        }
        if(nums[n/2] != mini && nums[n/2] != maxi){
            return nums[n/2];
        }
        else if(nums[n/2-1] != mini && nums[n/2-1] != maxi){
            return nums[n/2-1];
        }
        else{
            return -1;
        }
    }
};