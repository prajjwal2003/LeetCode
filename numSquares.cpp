class Solution {
public:
    int numSquares(int n) {
        int temp = sqrt(n);
        if(temp*temp == n){
            return 1;
        }
        vector<int> dp(pow(10,4)+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=100; i++){
            dp[i*i] = 1;
        }
        for(int i=2; i<=n; i++){
            int temp = sqrt(i);
            int ans = INT_MAX;
            while(temp>0){
                ans = min(ans, dp[i-(temp*temp)]+1);
                temp--;
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};
