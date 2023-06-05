class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2){
            return true;
        }
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        bool ans = true;
        for(int i=2; i<coordinates.size(); i++){
            if((coordinates[i][1] - y2)*(coordinates[i][0] - x1) != (coordinates[i][1] - y1)*(coordinates[i][0] - x2)){
                ans = false;
                break;
            }
        }
        return ans;
    }
};