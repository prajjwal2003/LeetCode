class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> helper(A.size()+1, 0);
        vector<int> res(A.size(), 0);
        int ans = 0;
        for(int i=0; i<A.size(); i++){
            helper[A[i]]++;
            if(helper[A[i]] == 2){
                ans++;
            }
            helper[B[i]]++;
            if(helper[B[i]] == 2){
                ans++;
            }
            res[i] = ans;
        }
        return res;
    }
};