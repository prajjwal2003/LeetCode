class Solution {
public:
    int partitionString(string s) {
        set<char> box;
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            if(box.find(s[i]) != box.end()){
                ans++;
                for(auto j=box.begin(); j!=box.end(); j++){
                    box.erase(j);
                }
                box.insert(s[i]);
            }
            else{
                box.insert(s[i]);
            }
        }
        ans++;
        return ans;
    }
};