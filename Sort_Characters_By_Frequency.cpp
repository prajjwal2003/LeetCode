#include <unordered_map>
#include <queue>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto i = m.begin(); i!=m.end(); i++){
            pq.push({i->second, i->first});
        }
        string ans = "";
        while(!pq.empty()){
            int n = pq.top().first;
            char c = pq.top().second;
            int j = 0;
            while(j<n){
                ans+= c;
                j++;
            }
            pq.pop();
        }
        return ans;
    }
};