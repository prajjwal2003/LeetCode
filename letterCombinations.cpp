class Solution {
public:
    #include <unordered_map>
    vector<string> ans;
    void helper(vector<string>& vec, int i, string digits, string temp){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        string curr = vec[digits[i] - '0'];
        for(int j=0; j<curr.size(); j++){
            temp+= curr[j];
            helper(vec, i+1, digits, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return ans;
        }
        vector<string> vec(10);
        vec[2] = "abc";
        vec[3] = "def";
        vec[4] = "ghi";
        vec[5] = "jkl";
        vec[6] = "mno";
        vec[7] = "pqrs";
        vec[8] = "tuv";
        vec[9] = "wxyz";
        helper(vec, 0, digits, "");
        return ans;
    }
};