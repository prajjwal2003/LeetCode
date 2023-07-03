class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        set <char> box;
        bool twice = false;
        for(int i=0; i<s.size(); i++){
            if(box.find(s[i]) != box.end()){
                twice = true;
                break;
            }
            box.insert(s[i]);
        }
        if(s == goal && twice == true){
            return true;
        }
        int count = 0;
        bool ans = true;
        char s1, s2, g1, g2;
        for(int i=0; i<s.size(); i++){
            if(s[i] == goal[i]){
                continue;
            }
            if(count == 2){
                ans = false;
                break;
            }
            if(count == 0){
                s1 = s[i];
                g1 = goal[i];
            }
            else if(count == 1){
                s2 = s[i];
                g2 = goal[i];
            }
            count++;
        }
        if(!ans){
            return ans;
        }
        if(s1 == g2 && s2 == g1){
            return true;
        }
        else{
            return false;
        }
    }
};
