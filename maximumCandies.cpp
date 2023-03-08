class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(), candies.end());
        int i = 1;
        int j = candies[candies.size()-1];
        int res = 0;
        while(i<=j){
            int mid = (i+j)/2;
            long long temp = 0;
            for(int i=0; i<candies.size(); i++){
                temp+= candies[i]/mid;
            }
            if(temp < k){
                j = mid-1;
            }
            else{
                res = mid;
                i = mid+1;
            }
        }
        return res;
    }
};