class Solution {
public:
    vector<int> helper(vector<int>& result, vector<int> vec[], string& labels, int node, int parent){
        vector<int> ans(26, 0);
        char c = labels[node];
        int index = (int)c - (int)'a';
        ans[index] = 1;
        for(int i=0; i<vec[node].size(); i++){
            if(vec[node][i] != parent){
                vector<int> smallans = helper(result, vec, labels, vec[node][i], node);
                for(int i=0; i<26; i++){
                    ans[i]+= smallans[i];
                }
            }
        }
        result[node] = ans[index];
        return ans;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> vec[n];
        for(int i=0; i<edges.size(); i++){
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> result(n, 0);
        helper(result, vec, labels, 0, 0);
        return result;
    }
};