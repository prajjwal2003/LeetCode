#include <stack>
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> box1;
        stack<char> box2;
        for(int i=0; i<s.size(); i++){
            if(box1.empty() && s[i]=='#'){
                continue;
            }
            else if(s[i]=='#'){
                box1.pop();
            }
            else{
                box1.push(s[i]);
            }
        }
        for(int i=0; i<t.size(); i++){
            if(box2.empty() && t[i]=='#'){
                continue;
            }
            else if(t[i]=='#'){
                box2.pop();
            }
            else{
                box2.push(t[i]);
            }
        }
        while(!box1.empty() && !box2.empty()){
            if(box1.top() != box2.top()){
                return false;
            }
            box1.pop();
            box2.pop();
        }
        if(box1.empty() && box2.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};