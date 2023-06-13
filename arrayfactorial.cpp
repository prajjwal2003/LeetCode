#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n<=1){
        return n;
    }
    int smallans = factorial(n-1);
    return smallans * n;
}
int main() {
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        vec.push_back(a);
    }
    for(int i=0; i<n; i++){
        cout<<factorial(vec[i])<<" ";
    }
}
