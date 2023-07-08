class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            int j=i+1;
            bool inc = true;
            while(j<nums.size()){
                if(inc && nums[j]-nums[j-1]!=1){
                    ans = max(ans, j-i);
                    break;
                }
                if(!inc && nums[j]-nums[j-1]!=-1){
                    ans = max(ans, j-i);
                    break;
                }
                inc = !inc;
                j++;
            }
            ans = max(ans, j-i);
        }
        if(ans == 1){
            return -1;
        }
        return ans;
    }
};
