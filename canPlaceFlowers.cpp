class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        int count = 0;
        while(i<flowerbed.size()){
            if(flowerbed[i]==1){
                i+=2;
                continue;
            }
            if(i==flowerbed.size()-1){
                count++;
                i+=2;
                continue;
            }
            if(i<flowerbed.size()-1 && flowerbed[i+1]!=1){
                count++;
                i+=2;
                continue;
            }
            i+=3;
        }
        return count>=n;
    }
};