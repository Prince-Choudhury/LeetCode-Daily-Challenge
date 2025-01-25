class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        for(int i = 0; i<nums.size(); i++){
            int rem = target - nums[i];
            if(mp.find(rem)!=mp.end()){
                return {i, mp[rem]};
            }
            if(mp.find(rem) == mp.end()){
                mp[nums[i]] = i;
            }
        }

        return {};
    }
};