class Solution {
public:
    bool check(string& haystack, int i, string& needle){
        int j = i;
        int k = 0;
        while(j<haystack.size() && k<needle.size()){
            if(needle[k] != haystack[j]){
                return false;
            }
            j++;
            k++;
        }
        if(k==needle.size()){
            return true;
        }
        else{
            return false;
        }
    }
    int strStr(string haystack, string needle) {
        int ans = -1;
        for(int i=0; i<haystack.size(); i++){
            if(haystack[i] == needle[0]){
                if(check(haystack, i, needle)){
                    ans = i;
                    break;
                }
            }
        }
        return ans;
    }
};