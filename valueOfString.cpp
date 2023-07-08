#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    unordered_map<char, int> m;
    m['A'] = 10;
    m['B'] = 11;
    m['C'] = 12;
    m['D'] = 13;
    m['E'] = 14;
    m['F'] = 15;
    m['G'] = 16;
    int ans = 0, count = 0, i = s.size()-1;
    while(i>=0){
        int temp = (int)s[i] - (int)'0';
        if(temp >=0 && temp<=9){
            ans+= temp * pow(17, count);
        }
        else{
            ans+= m[s[i]] * pow(17, count);
        }
        count++;
        i--;
    }
    cout<<ans;
}
