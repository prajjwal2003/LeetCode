class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        bool found = false;
        char ans;
        for(int i=0; i<letters.size(); i++){
            if((letters[i] - 'a') - (target - 'a') > 0){
                found = true;
                ans = letters[i];
                break;
            }
        }
        if(found){
            return ans;
        }
        return letters[0];
    }
};