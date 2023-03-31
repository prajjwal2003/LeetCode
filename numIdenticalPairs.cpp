class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int conti = 1;
        int ans = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                conti++;
                if(i==nums.size()-1){
                    ans+= (conti*(conti-1))/2;
                }
                continue;
            }
            if(conti > 1){
                ans+= (conti*(conti-1))/2;
            }
            conti = 1;
        }
        return ans;
    }
};