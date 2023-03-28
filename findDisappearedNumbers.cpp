class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int temp = 1;
        vector<int> res; 
        for(int i=0; i<nums.size(); i++){
            if(temp > nums[i]){
                continue;
            }
            if(temp < nums[i]){
                while(temp < nums[i]){
                    res.push_back(temp);
                    temp++;
                }
                temp++;
            }
            else if(temp == nums[i]){
                temp++;
            }
        }
        while(temp <= nums.size()){
            res.push_back(temp);
            temp++;
        }
        return res;
    }
};