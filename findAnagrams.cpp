class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()){
            return {};
        }
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        int n = p.size();
        for(int i=0; i<n; i++){
            v2[s[i]-'a']++;
            v1[p[i]-'a']++;
        }
        vector<int> ans;
        if(v1==v2){
            ans.push_back(0);
        }
        for(int i=1; i<=s.size()-n; i++){
            v2[s[i-1]-'a']--;
            v2[s[i+n-1]-'a']++;
            if(v1==v2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};