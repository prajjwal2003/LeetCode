class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(int i=0; i<operations.size(); i++){
            string str = operations[i];
            if(str[0]=='+'){
                ans+= 1;
            }
            else if(str[0]=='-'){
                ans-= 1;
            }
            else if(str[1]=='+'){
                ans+= 1;
            }
            else{
                ans-= 1;
            }
        }
        return ans;
    }
};