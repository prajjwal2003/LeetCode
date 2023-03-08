class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long  i = 1;
        long long  j = (long long)time[0] * (long long)totalTrips;
        while(i<j){
            long long mid = (i+j)/2;
            long long k = 0;
            long long int temp = 0;
            while(k<time.size() && mid>=time[k]){
                temp+= mid/time[k];
                k++;
            }
            if(temp < totalTrips){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        return i;
    }
};