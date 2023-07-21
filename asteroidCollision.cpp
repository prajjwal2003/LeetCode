class Solution {
public:
    void reverse(stack<int>& s, vector<int>& ans){
        if(s.empty()){
            return;
        }
        int temp = s.top();
        s.pop();
        reverse(s, ans);
        ans.push_back(temp);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        s.push(asteroids[0]);
        for(int i=1; i<asteroids.size(); i++){
            if(s.empty() || asteroids[i] * s.top() > 0 || (s.top()<0 && asteroids[i]>0)){
                s.push(asteroids[i]);
                continue;
            }
            int temp = asteroids[i];
            bool flag = false;
            while(!s.empty() && s.top()>0 && temp < 0){
                int curr = s.top();
                s.pop();
                int mini = min(abs(temp), abs(curr));
                int maxi = max(abs(temp), abs(curr));
                if(mini == maxi){
                    flag = true;
                    break;
                }
                if(maxi == temp || maxi == curr){
                    temp = maxi;
                }
                else if(-1*maxi == temp || -1*maxi == curr){
                    temp = -1*maxi;
                }
            }
            if(flag){
                continue;
            }
            s.push(temp);
        }
        vector<int> ans;
        reverse(s, ans);
        return ans;
    }
};
