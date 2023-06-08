#include <map>
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> box;
        for(int i=0; i<arr1.size(); i++){
            box[arr1[i]]++;
        }
        vector<int> ans;
        for(int i=0; i<arr2.size(); i++){
            for(int j=0; j<box[arr2[i]]; j++){
                ans.push_back(arr2[i]);
            }
            box[arr2[i]] = 0;
        }
        for(auto it = box.begin(); it!=box.end(); it++){
            if(it->second == 0){
                continue;
            }
            for(int k=0; k<it->second; k++){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};