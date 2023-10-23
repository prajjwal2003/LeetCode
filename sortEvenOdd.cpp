class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even, odd;
        for(int i=0; i<nums.size(); i++){
            if(i%2 == 0){
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        int i = 0, j = 0;
        for(int k=0; k<nums.size(); k++){
            if(k%2==0){
                nums[k] = even[i];
                i++;
            }
            else{
                nums[k] = odd[j];
                j++;
            }
        }
        return nums;
    }
};
