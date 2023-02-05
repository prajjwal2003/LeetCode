class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()){
            return false;
        }
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        int n = s1.size();
        for(int i=0; i<n; i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(v1==v2){
            return true;
        }
        bool ans = false;
        for(int i=1; i<=s2.size()-n; i++){
            v2[s2[i-1]-'a']--;
            v2[s2[i+n-1]-'a']++;
            if(v1==v2){
                ans = true;
                break;
            }
        }
        return ans;
    }
};