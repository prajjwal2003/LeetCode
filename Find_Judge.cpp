class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> above(n+1);
        vector<int> below(n+1);
        for(int i=0; i<trust.size(); i++){
            below[trust[i][0]]++;
            above[trust[i][1]]++;
        }
        for(int i=1; i<above.size(); i++){
            if(above[i] == n-1 && below[i] == 0){
                return i;
            }
        }
        return -1;
    }
};