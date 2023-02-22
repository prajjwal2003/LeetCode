// minimum capacity have to be the max of all elements
// maximum capacity will be the total sum of all elements
// perform a binary search looking for a capacity and keep track of the days it require
class Solution {
public:
    int helper(vector<int>& weights, int mid){
        int ans = 0;
        int sum = 0;
        for(int i=0; i<weights.size(); i++){
            sum+= weights[i];
            if(sum>mid){
                ans++;
                sum = weights[i];
            }
        }
        return ans+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0;
        int mini = INT_MIN;
        for(int i=0; i<weights.size(); i++){
            maxi+= weights[i];
            mini = max(mini, weights[i]);
        }
        while(mini!=maxi){
            int mid = (mini+maxi)/2;
            int temp = helper(weights, mid);
            if(temp<=days){
                maxi = mid;
                continue;
            }
            mini = mid+1;
        }
        return mini;
    }
};