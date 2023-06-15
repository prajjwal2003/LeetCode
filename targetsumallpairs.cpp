#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        nums[i] = a;
    }
    int target;
    cin>>target;
    unordered_map<int, vector<int>> m;
    for(int i=0; i<nums.size(); i++){
        m[nums[i]].push_back(i);
    }
    for(auto it : m){
        int partner = target - it.first;
        if(m.count(partner) > 0){
            vector<int> temp1 = it.second;
            vector<int> temp2 = m[partner];
            for(int i=0; i<temp1.size(); i++){
                for(int j=0; j<temp2.size(); j++){
                    cout<<temp1[i]<<" "<<temp2[j]<<endl;
                }
            }
            m.erase(partner);
        }
    }
}
