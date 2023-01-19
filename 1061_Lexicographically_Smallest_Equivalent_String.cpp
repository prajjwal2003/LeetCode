#include <bits/stdc++.h>
class Solution {
public:
    struct DSU{
    public:
        vector<int> parent;
        DSU(int n){
            parent.resize(n);
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
            if(x<y){
                swap(x, y);
            }
            parent[x] = y;
        }
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
        for(int i=0; i<s1.size(); i++){
            dsu.merge(s1[i] - 97, s2[i] - 97);
        }
        string ans = "";
        for(int i=0; i<baseStr.size(); i++){
            char c = 97 + dsu.find(baseStr[i] - 97);
            ans+= c;
        }
        return ans;
    }
};
