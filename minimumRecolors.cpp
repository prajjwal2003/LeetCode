class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black = 0;
        for(int i=0; i<k; i++){
            if(blocks[i] == 'B'){
                black++;
            }
        }
        int ans = k-black;
        for(int i=1; i<=blocks.size()-k; i++){
            if(blocks[i-1] == 'B'){
                black--;
            }
            if(blocks[i+k-1] == 'B'){
                black++;
            }
            ans = min(ans, k-black);
        }
        return ans;
    }
};
