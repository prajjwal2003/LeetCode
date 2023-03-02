class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, k=0;
        while(i<chars.size()){
            int j = i+1;
            int len = 1;
            while(j<chars.size() && chars[j]==chars[i]){
                len++;
                j++;
            }
            chars[k++] = chars[i];
            i = j;
            if(len>1){
                string s = to_string(len);
                for(int p=0; p<s.size(); p++){
                    chars[k] = s[p];
                    k++;
                }
            }
        }
        return k;
    }
};