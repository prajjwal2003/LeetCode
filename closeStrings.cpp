class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        } 
        map<char, int> m1;
        map<char, int> m2;
        for(int i=0; i<word1.size(); i++){
            m1[word1[i]]++;
        }
        for(int i=0; i<word2.size(); i++){
            m2[word2[i]]++;
        }
        if(m1.size() != m2.size()){
            return false;
        }
        vector<int> v1;
        vector<int> v2;
        bool ans = true;
        for(auto it : m1){
            if(m2.find(it.first) == m2.end()){
                ans = false;
                break;
            }
            v1.push_back(it.second);
            v2.push_back(m2[it.first]);
        }
        if(!ans){
            return ans;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};
