class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        int i = 1;
        while(i<intervals.size()){
            if(intervals[i][0] > maxi){
                res.push_back({mini, maxi});
                mini = intervals[i][0];
                maxi = intervals[i][1];
                i++;
                continue;
            }
            maxi = max(maxi, intervals[i][1]);
            i++;
            continue;
        }
        res.push_back({mini, maxi});
        return res;
    }
};