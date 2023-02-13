class Solution {
public:
    int countOdds(int low, int high) {
        int temp = (high - low)/2;
        if(high%2==0 && low%2==0){
            return temp;
        }
        else{
            return temp+1;
        }
    }
};