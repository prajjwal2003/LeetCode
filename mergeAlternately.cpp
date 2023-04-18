class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string ans = "";
        int j = 0;
        while(i<word1.size() && j<word2.size()){
            ans+= word1[i];
            i++;
            ans+= word2[j];
            j++;
        }
        while(i<word1.size()){
            ans+= word1[i];
            i++;
        }
        while(j<word2.size()){
            ans+= word2[j];
            j++;
        }
        return ans;
    }
};