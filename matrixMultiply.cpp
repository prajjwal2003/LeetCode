#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    cin>>a>>b>>c;
    int v1[a][b];
    int v2[b][c];
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            int p;
            cin>>p;
            v1[i][j] = p;
        }
    }
    for(int i=0; i<b; i++){
        for(int j=0; j<c; j++){
            int p;
            cin>>p;
            v2[i][j] = p;
        }
    }
     int res[a][c];
    for(int i=0; i<a; i++){
        for(int j=0; j<c; j++){
            int temp = 0;
            int p=0;
            while(p<b){
                temp+= v1[i][p] * v2[p][j];
                p++;
            }
            res[i][j] = temp;
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<c; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
