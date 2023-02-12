class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        long long ans = 0;
        while(i<=j){
            if(i!=j){
                string s1 = to_string(nums[i]);
                string s2 = to_string(nums[j]);
                string temp = s1 + s2;
                long long sum = stoi(temp);
                ans+= sum;
            }
            else{
                string s1 = to_string(nums[i]);
                long long sum = stoi(s1);
                ans+= sum;
            }
            i++;
            j--;
        }
        return ans;
    }
};