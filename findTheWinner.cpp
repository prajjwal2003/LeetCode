class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        int temp = 1;
        while(q.size() > 1){
            if(temp < k){
                int pehla = q.front();
                q.pop();
                q.push(pehla);
                temp++;
                continue;
            }
            q.pop();
            temp = 1;
        }
        return q.front();
    }
};
