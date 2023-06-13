#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int temp = n;
    do{
        int sum = 0;
        while(temp>0){
            sum+= temp%10;
            temp/=10;
        }
        temp = sum;
    }while(temp/10 > 0);
    cout<<temp;
}
