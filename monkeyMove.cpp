class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int base, int n, int res){
        while(n>0){
            if(n%2==1){
                res = ((long)res * base) % mod;
            }
            base = ((long)base * base) % mod;
            n = n/2; 
        }
        return res%mod;
    }
    int monkeyMove(int n) {
        int ans = helper(2, n, 1);
        return (ans-2+mod) % mod;
    }
};