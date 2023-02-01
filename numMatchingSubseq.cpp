class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> temp(26);
        for(int i=0; i<s.size(); i++){
            temp[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            int last = -1;
            bool issubs = true;
            for(char j : words[i]){
                auto it = upper_bound(temp[j-'a'].begin(), temp[j-'a'].end(), last);
                if(it == temp[j-'a'].end()){
                    issubs = false;
                    break;
                }
                last = *it;
            }
            if(issubs){
                ans++;
            }
        }
        return ans;
    }
};