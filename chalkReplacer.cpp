class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for(int i=0; i<chalk.size(); i++){
            total+= chalk[i];
        }
        int sum = k%total;
        if(sum==0){
            return 0;
        }
        long long prefix = 0;
        int ans = 0;
        for(int i=0; i<chalk.size(); i++){
            if(prefix + chalk[i] > sum){
                ans = i;
                break;
            }
            prefix+= chalk[i];
        }
        return ans;
    }
};