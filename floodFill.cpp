class Solution {
public:
    void helper(int i, int j, vector<vector<int>>& image, int temp, int color){
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j] == color || image[i][j] != temp){
            return;
        }
        image[i][j] = color;
        helper(i-1, j, image, temp, color);
        helper(i+1, j, image, temp, color);
        helper(i, j-1, image, temp, color);
        helper(i, j+1, image, temp, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int temp = image[sr][sc];
        helper(sr, sc, image, temp, color);
        return image;
    }
};