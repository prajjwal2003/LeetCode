#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n==1){
        return n;
    }
    int smallans = factorial(n-1);
    return n*smallans;
}
bool checkstrong(int num){
    int temp = num;
    int sum = 0;
    while(temp>0){
        sum+= factorial(temp%10);
        temp/=10;
    }
    return sum==num;
}
int main() {
    int n;
    cin>>n;
    bool ans = check(n);
    if(ans){
        cout<<n<<" is a strong number";
    }
    else{
        cout<<n<<" is not a strong number";
    }
}
