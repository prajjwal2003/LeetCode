#include <set>
class Solution {
public:

    void helper(int n, set<int>& s){
        if(n==2){
            return;
        }
        for(int i=n-1; i>=2; i--){
            if(n%i == 1){
                s.insert(i);
                helper(i, s);
            }
        }
    }
    int distinctIntegers(int n) {
        set<int> s;
        s.insert(n);
        helper(n, s);
        return s.size();
    }
};