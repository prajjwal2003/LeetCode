#include <set>
#include <cstdlib>
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n= points.size();
        if(n<4){
            return 0;
        }
        set<vector<int>> box;
        bool flag = false;
        for(int i=0; i<points.size(); i++){
            box.insert(points[i]);
        }
        int ans= INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1]){
                    if(box.find({points[i][0], points[j][1]}) != box.end() && box.find({points[j][0], points[i][1]}) != box.end()){
                        flag = true;
                        int area = abs((points[j][0] - points[i][0]) * (points[j][1] - points[i][1]));
                        if(area < ans){
                            ans = area;
                        }
                    }
                }
            }
        }
        if(flag == true){
            return ans;
        }
        else{
            return 0;
        }
    }
};