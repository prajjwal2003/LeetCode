class Solution {
public:
    int minimizedStringLength(string s) {
        sort(s.begin(),  s.end());
        int ans = 0;
        for(int i=1; i<s.size(); i++){
            if(s[i] != s[i-1]){
                ans++;
            }
        }
        ans++;
        return ans;
    }
};