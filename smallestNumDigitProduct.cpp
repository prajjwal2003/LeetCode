#include <bits/stdc++.h>
using namespace std;
void helper(int n, vector<int>& nums){
    if(n/10 == 0){
        cout<<10+n<<endl;
        return;
    }
    for(int i=9; i>=2; i--){
        while(n%i==0){
            nums.push_back(i);
            n/=i;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums;
    helper(n, nums);
    string ans = "";
    for(int i=nums.size()-1; i>=0; i--){
        ans+= to_string(nums[i]);
    }
    if(ans.size() == 0){
        cout<<"Impossible";
    }
    else{
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }
}