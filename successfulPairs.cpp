class Solution {
public:
    int search(long digit, vector<int>& potions){
        int i = 0;
        int j = potions.size();
        while(i<j){
            int mid = (i+j)/2;
            if(potions[mid] >= digit){
                j = mid;
            }
            else{
                i = mid+1;
            }
        }
        return i;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        double temp = success;
        long num = 0;
        vector<int> ans(spells.size(), 0);
        for(int i=0; i<spells.size(); i++){
            num = search(ceil(temp/spells[i]), potions);
            ans[i] = potions.size()-num;
        }
        return ans;
    }
};