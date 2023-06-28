#include <iostream>
#include <vector>
using namespace std;
int helper(vector<int>& nums, int i){
    int max1, max2;
    if(nums[i] > nums[i+2]){
        max1 = nums[i];
        max2 = nums[i+2];
    }
    else{
        max1 = nums[i+2];
        max2 = nums[i];
    }
    if(i+4 >= nums.size()){
        return max2;
    }
    for(int j=i+4; j<nums.size(); j+=2){
        if(nums[j] >= max1){
            max2 = max1;
            max1 = nums[j];
            continue;
        }
        else if(nums[j] < max1 && nums[j] > max2){
            max2 = nums[j];
        }
    }
    return max2;
}
int main() {
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    if(n<4){
        cout<<"Not Possible"<<endl;
    }
    else{
        int ans1 = helper(nums, 0);
        int ans2 = helper(nums, 1);
        cout<<ans1+ans2<<endl;
    }
}
