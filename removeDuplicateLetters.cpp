class Solution {
public:
    string removeDuplicateLetters(string s) {
        set<int> box;
        unordered_map<int, int> m;
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            m[(int)s[i] - (int)'a']++;
        }
        for(int i=0; i<s.size(); i++){
            m[(int)s[i] - (int)'a']--;
            if(box.find((int)s[i] - (int)'a') != box.end()){
                continue;
            }
            while(!st.empty() && (int)s[i]-(int)'a' < st.top() && m[st.top()] > 0){
                box.erase(st.top());
                st.pop();
            }
            st.push((int)s[i] - (int)'a');
            box.insert((int)s[i] - (int)'a');
        }
        string ans = "";
        while(!st.empty()){
            ans+= st.top() + 'a';
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
