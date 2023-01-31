#include <unordered_map>
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool ans = true;
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for(int i=0; i<s.size(); i++){
            if(m1.count(s[i]) > 0){
                if(t[i] != m1[s[i]]){
                    ans = false;
                    break;
                }
            }
            else{
                if(m2.count(t[i]) > 0){
                    ans = false;
                    break;
                }
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
        }
        return ans;
    }
};