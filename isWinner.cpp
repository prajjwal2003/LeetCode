class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = 0;
        int score2 = 0;
        for(int i=0; i<player1.size(); i++){
            if(i-2>=0 && player1[i-2] == 10){
                score1+= 2*player1[i];
            }
            else if(i-1>=0 && player1[i-1]==10){
                score1+= 2*player1[i];
            }
            else{
                score1+= player1[i];
            }
            if(i-2>=0 && player2[i-2] == 10){
                score2+= 2*player2[i];
            }
            else if(i-1>=0 && player2[i-1]==10){
                score2+= 2*player2[i];
            }
            else{
                score2+= player2[i];
            }
        }
        if(score1 > score2){
            return 1;
        }
        else if(score2 > score1){
            return 2;
        }
        else{
            return 0;
        }
        
    }
};