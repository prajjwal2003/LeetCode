class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = 1000005;
        bool prime[n+1];
        vector<int> primenums;
        memset(prime, true, sizeof(prime));
        prime[1] = false;
        for(int i=2; i*i<=n; i++){
            if(prime[i] == true){
                for(int j=i*i; j<=n; j+=i){
                    prime[j] = false;
                }
            }
        }
        vector<int> ans({-1, -1});
        int diff = INT_MAX;
        vector<int> sel;
        for(int i=left; i<=right; i++){
            if(prime[i] == true){
                sel.push_back(i);
            }
        }
        if(sel.size() < 2){
            return ans;
        }
        int newdiff;
        for(int i=1; i<sel.size(); i++){
            newdiff = sel[i] - sel[i-1];
            if(newdiff < diff){
                ans[0] = sel[i-1];
                ans[1] = sel[i];
                diff = newdiff;
            } 
        }
        return ans;
    }
};