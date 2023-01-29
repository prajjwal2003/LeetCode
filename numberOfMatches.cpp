class Solution {
public:
    int numberOfMatches(int n) {
        if(n==1){
            return 0;
        }
        int ans = 0;
        while(n!=1){
            if(n%2==0){
                ans+= n/2;
                n = n/2;
                continue;
            }
            ans+= n/2;
            n = n/2 + 1;
        }
        return ans;
    }
};