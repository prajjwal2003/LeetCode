class Solution {
public:
    vector<vector<string>> ans;
    bool check(string str){
        int n = str.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            if(str[i] == str[j]){
                i++;
                j--;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void helper(string s, int i, vector<string> temp){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        string curr = "";
        for(int j=i; j<s.size(); j++){
            curr+= s[j];
            if(check(curr)){
                temp.push_back(curr);
                helper(s, j+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        helper(s, 0, temp);
        return ans;    
    }
};