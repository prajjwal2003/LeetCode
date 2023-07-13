class Solution {
public:
    int find(vector<int>& adj, int x){
        if(x == adj[x]){
            return x;
        }
        adj[x] = find(adj, adj[x]);
        return adj[x];
    }
    void Union(vector<int>& adj, int x, int y){
        if(find(adj, x) == find(adj, y)){
            return;
        }
        adj[x] = y;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj(n);
        for(int i=0; i<n; i++){
            adj[i] = i;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j || isConnected[i][j] == 0){
                    continue;
                }
                int par1 = find(adj, i);
                int par2 = find(adj, j);
                Union(adj, par1, par2);
                isConnected[j][i] = 0;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i == adj[i]){
                ans++;
            }
        }
        return ans;
    }
};
