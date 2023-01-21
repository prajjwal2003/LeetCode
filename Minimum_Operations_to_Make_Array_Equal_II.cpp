#include <cstdlib>
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        if(k==0){
            for(int i=0; i<n; i++){
                if(nums1[i]!=nums2[i]){
                    return -1;
                }
            }
            return 0;
        }
        long long diff = 0;
        long long ans = 0;
        for(int i=0; i<n; i++){
            diff+= nums1[i] - nums2[i];
            long long curr = abs(nums1[i] - nums2[i]);
            if(curr%k != 0){
                return -1;
            }
            ans+= curr/k;
        }
        if(diff==0){
            return ans/2;
        }
        else{
            return -1;
        }
    }
};