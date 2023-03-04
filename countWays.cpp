#include <bits/stdc++.h>
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        long long count = 0, maxi = ranges[0][1], mod = 1000000007;
        for(int i=1; i<ranges.size(); i++){
            if(ranges[i][0] > maxi){
                count++;
            }
            maxi = max(maxi, (long long)ranges[i][1]);
        }
        count++;
        long long ans = 1;
        for(int i=0; i<count; i++){
            ans = (ans*2) % mod;
        }
        int res = ans % mod;
        return res;
    }
};