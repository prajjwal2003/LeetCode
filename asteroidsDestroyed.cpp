class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long weight = mass;
        bool ans = true;
        for(int i=0; i<asteroids.size(); i++){
            if(weight < asteroids[i]){
                ans = false;
                break;
            }
            weight+= asteroids[i];
        }
        return ans;
    }
};
