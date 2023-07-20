class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.size(); i++){
            if((int)s[i] >=97 && (int)s[i] <= 122){
                continue;
            }
            else if((int)s[i] >=65 && (int)s[i] <=90){
                s[i] = (int)s[i] + 32;
            }
        }
        return s;
    }
};
