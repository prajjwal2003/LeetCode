#include <map>
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int rem = nums.size();
        for(auto i=m.rbegin(); i!=m.rend(); i++){
            i->second = rem - i->second;
            rem = i->second;
        }
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++){
            ans[i] = m[nums[i]];
        }
        return ans;
    }
};