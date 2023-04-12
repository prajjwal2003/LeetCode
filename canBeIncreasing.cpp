class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
      int prev = nums[0];
			bool used = false;
			for(int i=1; i<nums.size(); i++){
				if(nums[i] <= prev){
					if(used == true){
						return false;
					}
					used = true;
					if(i==1 || nums[i] > nums[i-2]){
						prev = nums[i];
					}
				}
				else{
					prev = nums[i];
				}
			}
			return true;
    }
};