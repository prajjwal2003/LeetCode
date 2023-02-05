# include <queue>
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i=0; i<gifts.size(); i++){
            pq.push(gifts[i]);
        }
        while(k>0){
            int temp = pq.top();
            pq.pop();
            temp = sqrt(temp);
            pq.push(temp);
            k--;
        }
        long long ans = 0;
        while(!pq.empty()){
            ans+= pq.top();
            pq.pop();
        }
        return ans;
    }
};