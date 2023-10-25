class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size());
        for(int i=nums.size()-2; i>=0; i--){
            while(!s.empty() && nums[i] >= s.top()){
                s.pop();
            }
            s.push(nums[i]);
        }
        for(int i=nums.size()-1; i>=0; i--){
            while(!s.empty() && nums[i] >= s.top()){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = s.top();
            }
            s.push(nums[i]);
        }
        return ans;
    }
};
