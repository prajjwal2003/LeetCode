#include <map>
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> row;
        map<vector<int>, int> col;
        for(int i=0; i<n; i++){
            row[grid[i]]++;
        }
        for(int j=0; j<n; j++){
            vector<int> temp;
            for(int i=0; i<n; i++){
                temp.push_back(grid[i][j]);
            }
            col[temp]++;
        }
        int ans = 0;
        for(auto it : row){
            vector<int> vec = it.first;
            if(col.count(vec) > 0){
                ans+= it.second * col[vec];
            }
        }
        return ans;
    }
};