class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string> box;
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            string str = words[i];
            string rev = string(str.rbegin(), str.rend());
            if(box.find(rev) != box.end()){
                ans++;
            }
            box.insert(words[i]);
        }
        return ans;
    }
};
