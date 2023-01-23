#include <unordered_map>
#include <queue>
class Solution {
public:
    class comp{
    public:
        bool operator()(pair<int, string>& a, pair<int, string>& b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
            for(auto i : m){
                if(pq.size() < k){
                    pq.push({i.second, i.first});
                }
                else{
                    if(i.second > pq.top().first){
                        pq.pop();
                        pq.push({i.second, i.first});
                    }
                    else if(i.second == pq.top().first && i.first < pq.top().second){
                        pq.pop();
                        pq.push({i.second, i.first});
                    }
                }
            }
            vector<string> ans;
            while(!pq.empty()){
                ans.push_back(pq.top().second);
                pq.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
    }
};