class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> box;
        for(int i=0; i<allowed.size(); i++){
            box.insert(allowed[i]);
        }
        int ans = 0;
        for(auto i : words){
            bool consistent = true;
            for(char c : i){
                if(box.find(c) == box.end()){
                    consistent = false;
                    break;
                }
            }
            if(consistent){
                ans++;
            }
        }
        return ans;
    }
};