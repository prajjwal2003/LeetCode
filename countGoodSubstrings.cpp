class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3){
            return 0;
        }
        unordered_map<char, int> box;
        box[s[0]]++;
        box[s[1]]++;
        box[s[2]]++;
        int ans = 0;
        for(int i=2; i<s.size(); i++){
            if(box.size() == 3){
                ans++;
            }
            if(i<s.size()-1){
                box[s[i-2]]--;
                if(box[s[i-2]] == 0){
                    box.erase(s[i-2]);
                }
                box[s[i+1]]++;
            }
        }
        return ans;
    }
};
