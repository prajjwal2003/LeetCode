class Solution {
public:
    #include <queue>
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        for(int i=0; i<tickets.size(); i++){
            q.push({tickets[i], i});
        }
        int time = 0;
        int ans;
        while(!q.empty()){
            pair<int, int> temp = q.front();
            time++;
            q.pop();
            temp.first--;
            if(temp.first != 0){
                q.push(temp);
                continue;
            }
            if(temp.second == k){
                ans = time;
                break;
            }
        }
        return ans;
    }
};
