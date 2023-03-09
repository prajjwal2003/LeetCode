// max speed should be 1e7
// and min speed should be 1
#include <cmath>
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= dist.size()-1){
            return -1;
        }
        int i = 1;
        int j = 1e7;
        while(i<j){
            int mid = (i+j)/2;
            double temp = 0.0;
            for(int i=0; i<dist.size()-1; i++){
                double d = (double)dist[i]/mid;
                temp+= ceil(d);
            }
            temp+= (double)dist[dist.size()-1]/mid;
            if(temp > hour){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        return i;
    }
};