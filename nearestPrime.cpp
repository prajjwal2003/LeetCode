#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> arr, int i, int j, int num){
    if(i>j){
        return i;
    }
    int mid = (i+j)/2;
    if(arr[mid] <= num){
        return helper(arr, mid+1, j, num);
    }
    return helper(arr, i, mid-1, num);
}
int main() {
    int n = 100000;
    bool prime[n+1];
    vector<int> primenums;
    memset(prime, true, sizeof(prime));
    for(int i=2; i*i<=n; i++){
        if(prime[i] == true){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }
    for(int i=0; i<=n; i++){
        if(prime[i] == true){
            primenums.push_back(i);
        }
    }
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        if(num==1){
            cout<<2<<endl;
            break;
        }
        int upper = helper(primenums, 0, primenums.size()-1, num);
        if(primenums[upper-1] == num){
            cout<<num<<endl;
        }
        else if(abs(primenums[upper] - num) < abs(primenums[upper-1] - num)){
            cout<<primenums[upper]<<endl;
        }
        else{
            cout<<primenums[upper-1]<<endl;
        }
    }
}
