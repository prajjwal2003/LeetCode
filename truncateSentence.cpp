class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int i = 0;
        while(k>0){
            if(s[i] == ' '){
                k--;
                if(k>0){
                    ans+= ' ';
                }
                i++;
                continue;
            }
            else if(i==s.size()-1){
                k--;
                ans+= s[i];
                break;
            }
            ans+= s[i];
            i++;
        }
        return ans;
    }
};