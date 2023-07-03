class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        int count = 0;
        bool ans = true;
        char st1, st2, g1, g2;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] == s2[i]){
                continue;
            }
            if(count == 2){
                ans = false;
                break;
            }
            if(count == 0){
                st1 = s1[i];
                g1 = s2[i];
            }
            else if(count == 1){
                st2 = s1[i];
                g2 = s2[i];
            }
            count++;
        }
        if(!ans){
            return ans;
        }
        if(st1 == g2 && st2 == g1){
            return true;
        }
        else{
            return false;
        }
    }
};
