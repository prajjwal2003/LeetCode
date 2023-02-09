class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 4){
            return *max_element(nums.begin(), nums.end());
        }
        vector<int> arr(nums.begin(), nums.end());
        int n= nums.size();
        int i=2;
        while(i<n-1){
            nums[i]= nums[i] + *max_element(nums.begin(), nums.begin()+i-1);
            i++;
            continue;
        }
        int ans1= *max_element(nums.begin(), nums.begin()+n-1);

        int j=3;
        while(j<n){
            arr[j]= arr[j] + *max_element(arr.begin()+1, arr.begin()+j-1);
            j++;
            continue;
        }
        int ans2= *max_element(arr.begin()+1, arr.begin()+n);
        if(ans1 > ans2){
            return ans1;
        }
        else{
            return ans2;
        }
    }
};