class Solution {
public:
    string removeTrailingZeros(string num) {
        int j = num.size()-1;
        while(num[j] == '0'){
            j--;
        }
        string ans = "";
        for(int i=0; i<=j; i++){
            ans+= num[i];
        }
        return ans;
    }
};