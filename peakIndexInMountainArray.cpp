class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 1;
        int j = arr.size()-2;
        int ans;
        int mid;
        while(i <= j){
            if(i==j){
                ans = i;
                break;
            }
            mid = (i+j)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                ans = mid;
                break;
            }
            else if(arr[mid] > arr[mid-1]){
                i = mid+1;
                continue;
            }
            else{
                j = mid-1;
                continue;
            }
        }
        return ans;
    }
};
