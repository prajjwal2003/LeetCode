#include <unordered_map>
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int maxi=INT_MIN;
        for(auto i=m.begin(); i!=m.end(); i++){
            if(i->second > maxi){
                maxi = i->second;
            }
        }
        vector<int> vec;
        for(auto i=m.begin(); i!=m.end(); i++){
            if(i->second == maxi){
                vec.push_back(i->first);
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<vec.size(); j++){
            int val= vec[j];
            int i=0;
            while(nums[i]!=val){
                i++;
            }
            int start = i;
            i = n-1;
            while(nums[i]!=val){
                i--;
            }
            int end = i;
            if(end - start + 1 < ans){
                ans = end - start + 1;
            }
        }
        return ans;
    }
};