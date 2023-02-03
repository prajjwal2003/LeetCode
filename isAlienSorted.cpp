#include <unordered_map>
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() == 1){
            return true;
        }
        unordered_map<char, int> m;
        for(int i=0; i<order.size(); i++){
            m[order[i]] = i;
        }
        bool ans = true;
        int i=0;
        while(i+1 < words.size()){
            bool temp = true;
            string one = words[i];
            string two = words[i+1];
            int j=0;
            int k=0;
            while(j<one.size() && k<two.size()){
                if(m[one[j]] < m[two[k]]){
                    break;
                }
                else if(m[one[j]] > m[two[k]]){
                    temp = false;
                    break;
                }
                else{
                    j++;
                    k++;
                }
            }
            if(temp == false){
                ans = false;
                break;
            }
            if(j!=one.size() && k==two.size()){
                ans = false;
                break;
            }
            i++;
        }
        return ans;
    }
};