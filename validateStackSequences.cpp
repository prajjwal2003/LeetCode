class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        int j = 0;
        while(i<pushed.size()){
            if(pushed[i] != popped[j]){
                s.push(pushed[i]);
                i++;
                continue;
            }
            j++;
            while(j<popped.size() && !s.empty() && popped[j] == s.top()){
                s.pop();
                j++;
            }
            i++;
        }
        return s.empty();
    }
};