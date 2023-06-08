#include <bits/stdc++.h>
using namespace std;
bool special(int num){
    int temp = num;
    int sum = 0;
    int prod = 1;
    while(temp > 0){
        sum+= temp%10;
        prod*= temp%10;
        temp/=10;
    }
    return sum+prod == num;
}
int main() {
    int m,n;
    cin>>m;
    cin>>n;
    for(int i=m; i<=n; i++){
        if(special(i)){
            cout<<i<<" ";
        }
    }
}
