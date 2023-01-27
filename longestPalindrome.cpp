#include <unordered_map>
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        bool odd = false;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        for(auto i : m){
            if(i.second%2==0){
                ans+= i.second;
            }
            else{
                odd = true;
                ans+= i.second - 1;
            }
        }
        if(odd==true){
            return ans+1;
        }
        else{
            return ans;
        }
    }
};