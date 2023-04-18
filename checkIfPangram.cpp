class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> check(26, false);
        for(int i=0; i<sentence.size(); i++){
            int index = sentence[i] - 'a';
            check[index] = true;
        }
        for(int i=0; i<26; i++){
            if(check[i] == false){
                return false;
            }
        }
        return true;
    }
};