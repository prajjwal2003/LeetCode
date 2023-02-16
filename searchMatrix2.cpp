class Solution {
public:

    bool rowcheck(vector<vector<int>>& matrix, int target, int i, int j){
        bool flag = false;
        for(int k=0; k<j; k++){
            if(matrix[i][k] == target){
                flag = true;
                break;
            }
        }
        return flag;
    }
    bool colcheck(vector<vector<int>>& matrix, int target, int i, int j){
        bool flag = false;
        int m = matrix.size();
        for(int k=i+1; k<m; k++){
            if(matrix[k][j] == target){
                flag = true;
                break;
            }
        }
        return flag;
    }
   
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        bool ans = false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        while(i<m && j>=0){
            if(matrix[i][j] == target){
                ans = true;
                break;
            }
            else if(matrix[i][j] > target){
                bool temp = rowcheck(matrix, target, i, j);
                if(temp==true){
                    ans = true;
                    break;
                }
                i++;
                j--;
            }
            else{
                bool temp = colcheck(matrix, target, i, j);
                if(temp==true){
                    ans = true;
                    break;
                }
                i++;
                j--;
            }
        }
        return ans;
    }
};