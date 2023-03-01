class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int>& res){
        if(amount == 0){
            return 0;
        }
        int smallans = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            if(amount-coins[i] >= 0){
                int temp=0;
                if(res[amount-coins[i]] != -1){
                    temp = res[amount-coins[i]];
                }
                else{
                    temp = helper(coins, amount-coins[i], res);
                }
                if(temp != INT_MAX && temp+1<smallans){
                    smallans = temp+1;
                }
            }
        }
        return res[amount] = smallans;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        vector<int> res(amount+1, -1);
        res[0] = 0;
        int ans = helper(coins, amount, res);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};