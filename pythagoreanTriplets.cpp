#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n/2; i++){
        for(int j=i+1; j<=n; j++){
            int square = i*i + j*j;
            float root = sqrt(square);
            if(root == floor(root)){
                cout<<i<<" "<<j<<" "<<root<<endl;
            }
        }
    }
}
