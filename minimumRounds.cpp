#include <unordered_map>
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(int i=0; i<tasks.size(); i++){
            m[tasks[i]]++;
        }
        int count=0;
        for(int i=0; i<tasks.size(); i++){
            if(m.size()==0){
                break;
            }
            if(m.count(tasks[i])==0){
                continue;
            }
            int n= m[tasks[i]];
            if(n%3==0){
                count+= n/3;
                m.erase(tasks[i]);
            }
            else if(n%3==1){
                if(n==1){
                    return -1;
                }
                count+= (n+2)/3;
                m.erase(tasks[i]);
            }
            else{
                count+= (n-2)/3 + 1;
                m.erase(tasks[i]);
            }
        }
        return count;
    }
};