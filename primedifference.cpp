#include <bits/stdc++.h>
#include <set>
using namespace std;
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
    int m, p;
    cin>>m>>p;
    int diff = 6;
    set<int> box;
    for(int i=m; i<=p; i++){
        if(prime[i] == true){
            box.insert(i);
        }
    }
    for(auto it = box.begin(); it!=box.end(); it++){
        int a = *it;
        if(box.count(6+a) > 0){
            cout<<a<<" "<<6+a<<endl;
        }
    }

}
