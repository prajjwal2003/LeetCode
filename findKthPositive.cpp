class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int j = arr.size()-1;
        while(i<j){
            int mid = (i+j)/2;
            int currmiss = arr[mid] - (mid+1);
            if(k>currmiss){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        int temp = arr[i] - (i+1);
        if(k>temp){
            return arr[i] + k-temp;
        }
        else{
            return arr[i] - (temp-k+1);
        }
    }
};