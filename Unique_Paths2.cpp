class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m==1 && n==1){
            return !obstacleGrid[0][0];
        }
        vector<vector<int>> vec(m, vector<int> (n));
        int i = 0;
        while(i<m){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            vec[i][0] = 1;
            i++;
        }
        while(i<m){
            vec[i][0] = 0;
            i++;
        }
        int j = 0;
        while(j<n){
            if(obstacleGrid[0][j] == 1){
                break;
            }
            vec[0][j] = 1;
            j++;
        }
        while(j<n){
            vec[0][j] = 0;
            j++;
        }
        for(int r=1; r<m; r++){
            for(int c=1; c<n; c++){
                if(obstacleGrid[r][c] == 1){
                    vec[r][c] = 0;
                    continue;
                }
                vec[r][c] = vec[r-1][c] + vec[r][c-1];
            }
        }
        return vec[m-1][n-1];
    }
};