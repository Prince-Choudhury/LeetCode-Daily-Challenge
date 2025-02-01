class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return true;
        }

        for(int i = 0; i<nums.size()-1; i++){
            int ele1 = nums[i];
            int ele2 = nums[i+1];
            if(((ele1 & 1) && (ele2 & 1)) || ((ele1 % 2 == 0) && (ele2 % 2 == 0))){
                return false;
                break;
            }

        }

        return true;
    }
};