class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if(purchaseAmount % 10 == 0){
            return 100 - purchaseAmount;
        }
        int temp;
        if(purchaseAmount%10 < 5){
            purchaseAmount -= purchaseAmount%10;
        }
        else{
            temp = 10 - (purchaseAmount%10);
            purchaseAmount+= temp;
        }
        
        return 100 - purchaseAmount;
    }
};
