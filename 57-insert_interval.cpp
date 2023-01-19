class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        int i;
        for(i=0; i<intervals.size(); i++){
            if(newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            else{
                break;
            }
        }
        int j;
        for(j=i; j<intervals.size(); j++){
            if(newInterval[1] < intervals[j][0]){
                ans.push_back(newInterval);
                break;
            }
            int mini = min(newInterval[0], intervals[j][0]);
            int maxi = max(newInterval[1], intervals[j][1]);
            newInterval = {mini, maxi};
        }
        if(j==intervals.size()){
            ans.push_back(newInterval);
        }
        for(int k=j; k<intervals.size(); k++){
            ans.push_back(intervals[k]);
        }
        return ans;
    }
};
