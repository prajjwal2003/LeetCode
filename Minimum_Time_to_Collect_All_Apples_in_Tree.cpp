class Solution {
public:

    int helper(vector<int> vec[], vector<bool>& hasApple, int node, int parent){
        int distance = 0;
        for(int i=0; i<vec[node].size(); i++){
            if(vec[node][i] != parent){
                int temp = helper(vec, hasApple, vec[node][i], node);
                if(hasApple[vec[node][i]]){
                    distance+= (2 + temp);
                    hasApple[node] = true;
                }
            }
        }
        return distance;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> vec[n];
        for(int i=0; i<edges.size(); i++){
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        return helper(vec, hasApple, 0, 0);
    }
};