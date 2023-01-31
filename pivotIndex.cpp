class Solution {
public:
    int (vector<int>& nums) {
        int total=0;
        for(int i=0; i<nums.size(); i++){
            nums[i]= nums[i] + total;
            total= nums[i];
        }
        if(total-nums[0]==0){
            return 0;
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]== total - nums[i]){
                return i;
            }
        }
        return -1;
    }
};