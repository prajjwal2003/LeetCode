class Solution {
public:
    long long coloredCells(int n) {
        if(n==1){
            return 1;
        }
        vector<long long> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        int k = 1;
        for(int i=2; i<=n; i++){
            ans[i]+= ans[i-1] + 4*k;
            k++;
        }
        return ans[n];
    }
};