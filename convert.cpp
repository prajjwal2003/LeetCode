class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int n = s.size();
        string ans = "";
        int j = 0;
        while(j<n){
            ans+= s[j];
            j+= 2*numRows-2;
        }
        for(int i=1; i<numRows-1; i++){
            j = i;
            int count = 0;
            while(j<n){
                ans+= s[j];
                if(count%2==0){
                    j+= (2*(numRows-i)) - 2;
                    count++;
                }
                else{
                    j+= 2*i;
                    count++;
                }
            }
        }
        j = numRows-1;
        while(j<n){
            ans+= s[j];
            j+= 2*(numRows-1);
        }
        return ans;
    }
};