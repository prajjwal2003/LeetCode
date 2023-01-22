class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1){
            return 1;
        }
        vector<vector<int>> vec(m, vector<int> (n));
        for(int i=1; i<m; i++){
            vec[i][0] = 1;
        }
        for(int j=1; j<n; j++){
            vec[0][j] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                vec[i][j] = vec[i][j-1] + vec[i-1][j];
            }
        }
        return vec[m-1][n-1];
    }
};