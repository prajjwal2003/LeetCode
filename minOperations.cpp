class Solution {
public:
    int helper(int n){
        if(n==0){
            return 1;
        }
        if(n == pow(2, (int)log2(n))){
            return 1;
        }
        int temp = (int)(log2(n));
        int low = pow(2, temp);
        int high = pow(2, temp+1);
        int lowdiff = n - low;
        int highdiff = high - n;
        if(lowdiff <= highdiff){
            return helper(lowdiff) + 1;
        }
        else{
            return helper(highdiff) + 1;
        }
    }
    int minOperations(int n) {
        return helper(n);
    }
};