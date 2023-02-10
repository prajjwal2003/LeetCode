class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> box(ideas.begin(), ideas.end());
        vector<vector<int>> vec(128, vector<int>(128, 0));

        long long ans = 0;
        for(int i=0; i<ideas.size(); i++){
            string word = ideas[i];
            for(char c='a'; c<='z'; c++){
                word[0] = c;
                if(box.find(word) == box.end()){
                    ans+= vec[c][ideas[i][0]];
                    vec[ideas[i][0]][c]++;
                }
            }
        }
        return ans*2;
    }
};