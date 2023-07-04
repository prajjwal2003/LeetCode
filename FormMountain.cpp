#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int>& nums, int left, int right, int mid){
    int size1 = mid-left+1;
    int size2 = right-mid;
    vector<int> lefty(size1);
    vector<int> righty(size2);
    for(int i=0; i<size1; i++){
        lefty[i] = nums[left + i];
    }
    for(int i=0; i<size2; i++){
        righty[i] = nums[mid+1+i];
    }
    int i=0, j=0, lef = left;
    while(i<size1 && j<size2){
        if(lefty[i] <= righty[j]){
            nums[lef] = lefty[i];
            i++;
        }
        else{
            nums[lef] = righty[j];
            j++;
        }
        lef++;
    }
    while(i<size1){
        nums[lef] = lefty[i];
        i++;
        lef++;
    }
    while(j<size2){
        nums[lef] = righty[j];
        j++;
        lef++;
    }
    lefty.clear();
    righty.clear();
}
void mergesort(vector<int>& nums, int i, int j){
    if(i>=j){
        return;
    }
    int mid = (i+j)/2;
    mergesort(nums, i, mid);
    mergesort(nums, mid+1, j);
    merge(nums, i, j, mid);
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
    mergesort(nums, 0, n-1);
    int i = n/2;
    int j = n-1;
    while(i<=j){
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
}
