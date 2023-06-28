#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s;
    cin>>s;
    stack<char> box;
    for(int i=s.size()-1; i>=0; i--){
        box.push(s[i]);
    }
    while(box.size() > 1){
        char one = box.top();
        box.pop();
        char two = box.top();
        box.pop();
        char three = box.top();
        box.pop();
        int first = (int)one - (int)'0';
        int third = (int)three - (int)'0';
        int ans;
        if(two == 'A'){
            ans = (first & third);
        }
        else if(two == 'B'){
            ans = (first | third);
        }
        else{
            ans = (first ^ third);
        }
        if(ans == 1){
            box.push('1');
        }
        else{
            box.push('0');
        }
    }
    cout<<box.top();
}
