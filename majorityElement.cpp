class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int req = nums.size() / 3 + 1;
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            int j = i;
            while(j<nums.size() && nums[j] == nums[i]){
                count++;
                j++;
            }
            j--;
            i = j;
            if(count >= req){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};