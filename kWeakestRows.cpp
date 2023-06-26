class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<mat.size(); i++){
            int count = 0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 1){
                    count++;
                }
                else{
                    break;
                }
            }
            pq.push({count, i});
        }
        vector<int> ans;
        while(k>0){
            pair<int, int> curr = pq.top();
            pq.pop();
            if(pq.empty()){
                ans.push_back(curr.second);
                break;
            }
            if(curr.first < pq.top().first){
                ans.push_back(curr.second);
                k--;
                continue;
            }
            if(curr.second < pq.top().second){
                ans.push_back(curr.second);
                k--;
                continue;
            }
            ans.push_back(pq.top().second);
            pq.pop();
            pq.push(curr);
            k--;
        }
        return ans;
    }
};