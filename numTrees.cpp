class Solution {
public:
    int numTrees(int n) {
        if(n < 2){
            return  n;
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            int temp = 0;
            for(int j=0; j<i; j++){
                if(j==0){
                    temp+= dp[i-j-1];
                }
                else if(j == i-1){
                    temp+= dp[j];
                }
                else{
                    temp+= dp[j] * dp[i-j-1];
                }
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};
