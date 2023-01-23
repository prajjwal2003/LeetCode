class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gassum = 0;
        int costsum = 0;
        for(int i=0; i<n; i++){
            gassum+= gas[i];
            costsum+= cost[i];
        }
        if(gassum < costsum){
            return -1;
        }
        int ans;
        int i = 0;
        while(i<n){
            int fuel = 0;
            int j = i;
            while(j<n && fuel>=0){
                fuel+= gas[j] - cost[j];
                j++;
            }
            if(j==n){
                ans = i;
                break;
            }
            i = j;
        }
        return ans;
    }
};