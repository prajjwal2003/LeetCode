class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> box;
        int ans = 0;
        int len = 0;
        int left = 0;
        for(int i=0; i<s.size(); i++){
            if(box.find(s[i]) == box.end()){
                box.insert(s[i]);
                len++;
                ans = max(ans, len);
                continue;
            }
            while(s[left]!=s[i]){
                box.erase(s[left]);
                left++;
            }
            left++;
            len = i-left+1;
            ans = max(ans, len);
        }
        return ans;
    }
};