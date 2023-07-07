#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main() {
    string s;
    cin>>s;
    vector<vector<char>> ans(s.size(), vector<char>(s.size()));
    for(int i=0; i<s.size(); i++){
        ans[i][i] = s[i];
        ans[s.size()-i-1][i] = s[i];
    }
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s.size(); j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}
