class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> v;
        int i= num.size()-1;
        int carry=0;
        
        while(i>=0 || k>0){
            int sum= carry;
            if(i>=0)sum+= num[i--];
            if(k>0)sum+= k%10;
            k= k/10;
            
            int a= sum%10;
            carry= sum/10;
            v.push_back(a);
        }
        if(carry>0){
            v.push_back(carry);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};