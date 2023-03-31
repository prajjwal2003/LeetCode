class Solution {
public:
    long long mod = 1e9 + 7;
    int numSub(string s) {
        long long ans = 0;
        long long conti = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                conti++;
                if(i==s.size()-1){
                    ans+= (conti*(conti+1))/2 % mod;
                }
                continue;
            }
            ans+= (conti*(conti+1))/2 % mod;
            conti = 0;
        }
        int res = ans % mod;
        return res;
    }
};