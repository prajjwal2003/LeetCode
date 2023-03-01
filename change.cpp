class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1));
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<amount+1; i++){
            dp[0][i] = i%coins[0]==0;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<amount+1; j++){
                long long temp = dp[i-1][j];
                if(j-coins[i] >= 0){
                    temp+= dp[i][j-coins[i]];
                }
                dp[i][j] = temp;
            }
        }
        return dp[n-1][amount];
    }
};