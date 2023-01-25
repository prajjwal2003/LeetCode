bool helper(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count=1;
        sort(points.begin(), points.end(), helper);
        int end= points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0] > end){
                count++;
                end= points[i][1];
            }
        }
        return count;
    }
};