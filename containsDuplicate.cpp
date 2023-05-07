class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> box;
        for(int i=0; i<nums.size(); i++){
            if(box.find(nums[i]) != box.end()){
                return true;
            }
            box.insert(nums[i]);
        }
        return false;
    }
};