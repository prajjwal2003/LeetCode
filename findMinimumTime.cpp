class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end() , [&](vector<int> a  , vector<int> b){
            return a[1] < b[1];
        });
        vector<bool> temp(2100, false);
        for(auto task : tasks){
            int start = task[0], end = task[1], time = task[2];
            for(int i=start; i<=end; i++){
                if(temp[i]==true){
                    time--;
                }
            }
            for(int i=end; time>0; i--){
                if(temp[i]==false){
                    temp[i] = true;
                    time--;
                }
            }
        }
        int count = 0;
        for(int i=0; i<2100; i++){
            if(temp[i]){
                count++;
            }
        }
        return count;
    }
};