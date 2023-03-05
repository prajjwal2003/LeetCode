class Solution {
public:
    int passThePillow(int n, int time) {
        vector<int> vec(n+1, -1);
        int i = 1;
        bool going = true;
        while(time > 0){
            if(going == true && i<n){
                i++;
            }
            else if(going == false && i>1){
                i--;
            }
            else if(i==n){
                going = false;
                i--;
            }
            else if(i==1){
                going = true;
                i++;
            }
            time--;
        }
        return i;
    }
};