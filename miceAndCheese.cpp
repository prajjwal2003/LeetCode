class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int> pq;
        long long sum = 0;
        for(int i=0; i<reward1.size(); i++){
            sum+= reward2[i];
            pq.push(reward1[i] - reward2[i]);
        }
        while(k){
            sum+= pq.top();
            pq.pop();
            k--;
        }
        int ans = sum;
        return ans;
    }
};