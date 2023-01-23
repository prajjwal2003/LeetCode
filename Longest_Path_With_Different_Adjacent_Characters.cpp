class Solution {
public:

    int result = 0;
    int helper(vector<int> vec[], string& s, int node, int parent){
        int ansnow = 1;
        int ansreturn = 1;
        int first = 0;
        int sec = 0;
        for(int i=0; i<vec[node].size(); i++){
            if(vec[node][i] != parent){
                int temp = helper(vec, s, vec[node][i], node);
                if(s[node] != s[vec[node][i]]){
                    if(temp+1 > ansreturn){
                        ansreturn = temp+1;
                    }
                    if(temp>first){
                        sec = first;
                        first = temp;
                    }
                    else if(temp>sec){
                        sec = temp;
                    }
                }
            }
        }
        ansnow+= first + sec;
        if(ansnow>result){
            result = ansnow;
        }
        return ansreturn;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> vec[n];
        for(int i=1; i<n; i++){
            vec[i].push_back(parent[i]);
            vec[parent[i]].push_back(i);
        }
        helper(vec, s, 0, 0);
        return result;
    }
};