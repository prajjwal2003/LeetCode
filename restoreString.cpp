class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = *max_element(indices.begin(), indices.end());
        string ans = "";
        for(int i=0; i<=n; i++){
            ans+= 'x';
        }
        for(int i=0; i<indices.size(); i++){
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};