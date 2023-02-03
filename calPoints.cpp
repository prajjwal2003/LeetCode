#include <stack>
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i=0; i<operations.size(); i++){
            if(operations[i]=="C"){
                s.pop();
            }
            else if(operations[i]=="D"){
                s.push(2*s.top());
            }
            else if(operations[i]=="+"){
                int a= s.top();
                s.pop();
                int b= s.top();
                s.push(a);
                s.push(a+b);
            }
            else{
                s.push(stoi(operations[i]));
            }
        }
        int ans=0;
        while(!s.empty()){
            ans+= s.top();
            s.pop();
        }
        return ans;
    }
};