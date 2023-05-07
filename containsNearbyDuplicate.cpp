class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> box;
        for(int i=0; i<nums.size(); i++){
            if(box.find(nums[i]) == box.end()){
                box[nums[i]] = i;
                continue;
            }
            if(abs(i - box[nums[i]]) <= k){
                return true;
            }
            box[nums[i]] = i;
        }
        return false;
    }
};