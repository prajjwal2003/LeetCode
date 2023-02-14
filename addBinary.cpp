class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int i= a.length()-1;
        int j= b.length()-1;
        int carry=0;
        while(i>=0 || j>=0){
            int sum= carry;
            if(i>=0){
                sum+= a[i--] - '0';
            }
            if(j>=0){
                sum+= b[j--] - '0';
            }
            
            if(sum>1){
                carry= 1;
            }
            else{
                carry=0;
            }
            
            if(sum%2==0){
                s+= '0';
            }
            else{
                s+= '1';
            }
            
        }
        if(carry==1){
            s+= '1';
        }
        reverse(s.begin(), s.end());
        return s;
    }
};