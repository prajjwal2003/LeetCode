class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char first;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '9'){
                continue;
            }
            first = s[i];
            break;
        }
        
        string maxi = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]==first){
                maxi+= '9';
            }
            else{
                maxi+= s[i];
            }
        }
        string mini= "";
        char zero = s[0];
        for(int i=0; i<s.size(); i++){
            if(s[i]==zero){
                mini+= '0';
            }
            else{
                mini+= s[i];
            }
        }
        int maximum = stoi(maxi);
        int minimum = stoi(mini);
        int ans = maximum - minimum;
        return ans;
    }
};