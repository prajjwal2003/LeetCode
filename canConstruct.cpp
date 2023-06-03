class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> box;
        for(int i=0; i<magazine.size(); i++){
            box[magazine[i]]++;
        }
        bool ans = true;
        for(int i=0; i<ransomNote.size(); i++){
            if(box.count(ransomNote[i])==0 || box[ransomNote[i]]<=0){
                ans = false;
                break;
            }
            box[ransomNote[i]]--;
        }
        return ans;
    }
};