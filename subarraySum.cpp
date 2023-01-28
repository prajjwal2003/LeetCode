#include <unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i] + sum;
            sum = nums[i];
            if(m.count(sum-k) > 0){
                ans+= m.at(sum-k);
            }
            m[sum]++;
        }
        return ans;
    }
};