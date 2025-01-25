class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        int n = nums.size();
        n = n/2;

        for(auto i : mpp){
            if(i.second>n){
               return i.first;
            }
        }
        return -1;
    }
};