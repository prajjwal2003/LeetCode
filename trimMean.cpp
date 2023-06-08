class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cut = arr.size() / 20;
        double sum = 0;
        int count = 0;
        for(int i=cut; i<arr.size()-cut; i++){
            sum+= arr[i];
            count++;
        }
        double ans = sum/count;
        return ans; 
    }
};