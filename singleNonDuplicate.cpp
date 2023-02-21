class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans;
        int i=0, j=nums.size()-1;
        while(i <= j){
            if(i==j){
                ans = nums[i];
                break;
            }
            int mid = (i+j)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                ans = nums[mid];
                break;
            }
            else if(nums[mid]==nums[mid-1]){
                if(mid%2==0){
                    j = mid-2;
                    continue;
                }
                else{
                    i = mid+1;
                    continue;
                }
            }
            else{
                if(mid%2==0){
                    i = mid+2;
                    continue;
                }
                else{
                    j = mid-1;
                    continue;
                }
            }
        }
        return ans;
    }
};