#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int ans = INT_MIN;
    for(int i=0; i<s.size(); i++){
        if((int)s[i] < 48 || (int)s[i] > 57){
            continue;
        }
        string temp = "";
        bool small = true;
        while((int)s[i] >=48 && (int)s[i] <=57){
            if((int)s[i] == 57){
                small = false;
                break;
            }
            temp+= s[i];
            i++;
        }
        if(small){
            int num = stoi(temp);
            ans = max(ans, num);
        }
        else{
            while(i<s.size() && (int)s[i] >=48 && (int)s[i] <=57){
                i++;
            }
        }
    }
    cout<<ans<<endl;
}
