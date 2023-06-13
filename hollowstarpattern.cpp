#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=0;
    while(i<n){
        int j=0;
        while(j<n){
            if(i!=0 && j!=0 && i!=n-1 && j!=n-1){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
            j++;
        }
        i++;
        cout<<endl;
    }
}