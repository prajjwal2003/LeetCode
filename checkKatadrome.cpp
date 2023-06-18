#include <bits/stdc++.h>
using namespace std;
bool helper(int n){
    if(n/10 == 0){
        return true;
    }
    int mini = n%10;
    n/=10;
    while(n>0){
        if(n%10 < mini){
            return false;
        }
        mini = n%10;
        n/=10;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    bool ans = helper(n);
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
