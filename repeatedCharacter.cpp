#include <set>
class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> box;
        char ans;
        for(int i=0; i<s.size(); i++){
            if(box.find(s[i]) != box.end()){
                ans = s[i];
                break;
            }
            box.insert(s[i]);
        }
        return ans;
    }
};