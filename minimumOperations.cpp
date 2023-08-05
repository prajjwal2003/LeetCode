class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> s;
        int i = 0;
        while(i<nums.size()){
            s.insert(nums[i]);
            i++;
        }
        if(nums[0] == 0){
            return s.size()-1;
        }
        return s.size();
    }
};
