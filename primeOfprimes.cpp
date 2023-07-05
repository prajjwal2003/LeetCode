#include <iostream>
#include <vector>
using namespace std;
int digsum(int num){
    int ans = 0;
    while(num>0){
        ans+= num%10;
        num/=10;
    }
    return ans;
}
int helper(vector<bool>& prime, int n){
    int var = 0;    
    while(n/10 > 0){
        if(!prime[n]){
            break;
        }
        cout<<n<<" ";
        var++;
        n = digsum(n);
    }
    if(prime[n]){
        cout<<n<<" ";
        var++;
    }
    return var;
}
int main() {
    int n = 100000;
    vector<bool>prime(n+1, true);
    for(int i=2; i*i<=n; i++){
        if(prime[i] == true){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }
    for(int i=11; i<1000; i++){
        int ans = helper(prime, i);
        if(ans){
            cout<<"-> "<<ans<<endl;
        }
    }
}
