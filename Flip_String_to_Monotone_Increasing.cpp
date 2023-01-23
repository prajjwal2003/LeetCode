// APPROACH
// kahin bhi 1 rkhne mein dikkat nhi h 
// lekin jab 0 aata h to:
// 1. yaa to 0 rkho(pichhle sab 1 ko 0 krro)
// 2. yaa 1 rkho(pichhle flips ke baad ab 1 flip aur krro)
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones=0;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                ones++;
                continue;
            }
            ans= min(ans+1, ones);
        }
        return ans;
    }
};