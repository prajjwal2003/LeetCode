class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i=0; i<n; i++){
            reverse(image[i].begin(), image[i].end());
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                image[i][j] = !image[i][j];
            }
        }
        return image;
    }
};