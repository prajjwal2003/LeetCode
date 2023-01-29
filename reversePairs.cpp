class Solution {
public:
    int res = 0;
    void merge(vector<int>& nums, int i, int middle, int j){
        vector<int> temp;
        int a = i;
        int b = middle + 1;
        while(a<=middle && b<=j){
            if(nums[a] > (long long)2 * nums[b]){
                res+= middle-a+1;
                b++;
            }
            else{
                a++;
            }
        }
        a = i;
        b = middle + 1;
        while(a<=middle && b<=j){
            if(nums[a] <= nums[b]){
                temp.push_back(nums[a]);
                a++;
            }
            else{
                temp.push_back(nums[b]);
                b++;
            }
        }
        if(a == middle+1){
            while(b<=j){
                temp.push_back(nums[b]);
                b++;
            }
        }
        else{
            while(a<=middle){
                temp.push_back(nums[a]);
                a++;
            }
        }
        int index = 0;
        for(int p=i; p<=j; p++){
            nums[p] = temp[index];
            index++;
        }
    }
    void mergesort(vector<int>& nums, int i, int j){
        if(i>=j){
            return;
        }
        int mid = (i+j)/2;
        mergesort(nums, i, mid);
        mergesort(nums, mid+1, j);
        merge(nums, i, mid, j);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return res;
    }
};