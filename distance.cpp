class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long, vector<long long>> box;
        for(int i=0; i<nums.size(); i++){
            box[nums[i]].push_back(i);
        }
        vector<long long> ans(nums.size());
        for(auto i : box){
            vector<long long> temp = i.second;
            long long total = 0;
            for(int j=0; j<temp.size(); j++){
                total+= (long long)temp[j];
            }
            long long prefix = 0;
            for(int j=0; j<temp.size(); j++){
                ans[temp[j]] = (temp[j] * j) - (temp[j] * (temp.size()-j-1)) - prefix + (total-prefix-temp[j]);
                prefix+= temp[j];
            }
        }
        return ans;
    }
};

