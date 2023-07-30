class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        sort(hours.begin(), hours.end());
        int i = 0;
        while(i<hours.size()){
            if(hours[i] >= target){
                break;
            }
            i++;
        }
        return hours.size()-i;
    }
};
