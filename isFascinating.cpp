#include <set>
class Solution {
public:
    bool isFascinating(int n) {
        set<char> s;
        string str = to_string(n);
        str+= to_string(2*n);
        str+= to_string(3*n);
        if(str.size() != 9){
            return false;
        }
        for(int i=0; i<str.size(); i++){
            s.insert(str[i]);
        }
        if(s.size() == 9 && s.find('0') == s.end()){
            return true;
        }
        else{
            return false;
        }
    }
};