class Solution {
public:
    bool check(string s){
        int n = s.size()-1;
        if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u' || s[0]=='A' || s[0]=='E' || s[0]=='I' || s[0]=='O' || s[0]=='U'){
            if(s[n]=='a' || s[n]=='e' || s[n]=='i' || s[n]=='o' || s[n]=='u' || s[n]=='A' || s[n]=='E' || s[n]=='I' || s[n]=='O' || s[n]=='U'){
                return true;
            }
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> temp(words.size());
        if(check(words[0])){
            temp[0] = 1;
        }
        else{
            temp[0] = 0;
        }
        for(int i=1; i<words.size(); i++){
            if(check(words[i])){
                temp[i] = temp[i-1] + 1;
            }
            else{
                temp[i] = temp[i-1];
            }
        }
        
        vector<int> res;
        for(int i=0; i<queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            if(left==0){
                res.push_back(temp[right]);
            }
            else{
                res.push_back(temp[right] - temp[left-1]);
            }
        }
        return res;
    }
};