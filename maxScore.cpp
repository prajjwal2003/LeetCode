class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

        for(int i=0; i<nums1.size(); i++){
            pq1.push({nums1[i], i});
        }
        long long sum = 0;
        int count = k;
        while(count>0){
            sum+= pq1.top().first;
            pq2.push({nums2[pq1.top().second], pq1.top().second});
            pq1.pop();
            count--;
        }
        long long score = sum * pq2.top().first;
        while(!pq1.empty()){
            sum-= nums1[pq2.top().second];
            pq2.pop();
            sum+= pq1.top().first;
            pq2.push({nums2[pq1.top().second], pq1.top().second});
            pq1.pop();
            score = max(score, sum*pq2.top().first);
        }
        return score;
    }
};