class Solution {
public:

    int helper(int num){
        int ans = 0;
        while(num > 0){
            int last = num%10;
            ans+= last * last;
            num /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = helper(slow);
            fast = helper(helper(fast));
        }while(slow != fast);
        if(slow == 1){
            return true;
        }
        return false;
    }
};