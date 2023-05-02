class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        bool zero = false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero = true;
                break;
            }
            else if(nums[i] < 0){
                count++;
            }
        }
        if(zero){
            return 0;
        }
        if(count%2==0){
            return 1;
        }
        else{
            return -1;
        }
    }
};