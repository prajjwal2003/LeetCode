#include <bits/stdc++.h>
class Solution {
public:
    struct DSU{
        vector<int> parent;
        vector<int> size;

        DSU(int n){
            parent.resize(n);
            size.resize(n, 1);
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }
        int find(int x){
            if(x==parent[x]){
                return x;
            }
            return (parent[x] = find(parent[x]));
        }
        void merge(int x, int y){
            x = find(x);
            y = find(y);
            if(x==y){
                return;
            }
            if(size[x] > size[y]){
                swap(x, y);
            }
            size[y]+= size[x];
            parent[x] = y;
        }
    };


    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adjacent(n);
        for(int i=0; i<edges.size(); i++){
            adjacent[edges[i][0]].push_back(edges[i][1]);
            adjacent[edges[i][1]].push_back(edges[i][0]);
        }
        map<int, vector<int>> box;
        for(int i=0; i<vals.size(); i++){
            box[vals[i]].push_back(i);
        }
        DSU dsu(n);
        long long result = n;
        vector<bool> isActive(n);
        for(auto i = box.begin(); i!=box.end(); i++){
            vector<int> nodes = i->second;
            for(int j=0; j<nodes.size(); j++){
                for(auto child : adjacent[nodes[j]]){
                    isActive[nodes[j]] = true;
                    if(isActive[child]==true){
                        dsu.merge(nodes[j], child);
                    }
                }
            }
            vector<int> heads;
            for(int k=0; k<nodes.size(); k++){
                heads.push_back(dsu.find(nodes[k]));
            }
            sort(heads.begin(), heads.end());
            for(int j=0; j<heads.size(); j++){
                long long count = 0;
                int curr = heads[j];
                while(j<heads.size() && heads[j]==curr){
                    count++;
                    j++;
                }
                j--;
                result+= (count*(count-1))/2;
            }
        }
        return result;
    }
};
