// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1;
        long long j = n;
        int ans;
        while(i<=j){
            long long mid = (i+j)/2;
            if(isBadVersion(mid) == false){
                i = mid+1;
            }
            else{
                if(isBadVersion(mid-1) == false){
                    ans = mid;
                    break;
                }
                else{
                    j = mid-1;
                }
            }
        }
        return ans;
    }
};