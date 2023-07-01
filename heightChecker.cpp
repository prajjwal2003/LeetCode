class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int helper[heights.size()];
        for(int i=0; i<heights.size(); i++){
            helper[i] = heights[i];
        }
        sort(heights.begin(), heights.end());
        int ans = 0;
        for(int i=0; i<heights.size(); i++){
            if(heights[i] != helper[i]){
                ans++;
            }
        }
        return ans;
    }
};