class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> res(matrix[0].size());
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                res[j].push_back(matrix[i][j]);
            }
        }
        return res;
    }
};