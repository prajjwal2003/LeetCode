class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int dis = 0;
        while(mainTank >= 5){
            dis+= 50;
            if(additionalTank > 0){
                mainTank++;
                additionalTank--;
            }
            mainTank-=5;
        }
        dis+= mainTank*10;
        return dis;
    }
};