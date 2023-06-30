#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> ans(n);
    int maxAtTime;
    cin>> maxAtTime;
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        q.push({i, a});
    }
    int time = 0;
    while(!q.empty()){
        pair<int, int> temp = q.front();
        if(temp.second > maxAtTime){
            time+= 7;
            q.pop();
            q.push({temp.first, temp.second-maxAtTime});
        }
        else{
            if(temp.second < 4){
                time+= 2;
                q.pop();
                ans[temp.first] = time;
            }
            else{
                time+= 7;
                q.pop();
                ans[temp.first] = time;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}
