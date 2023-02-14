class Solution {
public:

    bool helper(vector<int>& vec, int target){
        bool ans = false;
        int  i = 0;
        int j = vec.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(target < vec[mid]){
                j = mid-1;
                continue;
            }
            else if(target > vec[mid]){
                i = mid+1;
                continue;
            }
            else{
                ans = true;
                break;
            }
        }
        return ans;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        int n = matrix[0].size();
        int i = 0;
        int j = matrix.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(target < matrix[mid][0]){
                j = mid-1;
                continue;
            }
            else if(target > matrix[mid][n-1]){
                i = mid+1;
                continue;
            }
            else{
                ans = helper(matrix[mid], target);
                break;
            }
        }
        return ans;
    }
};