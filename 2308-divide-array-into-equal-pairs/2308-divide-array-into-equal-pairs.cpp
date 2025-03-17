class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int>mpp;

        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto it = mpp.begin(); it!=mpp.end(); it++){
            if(it->second & 1){
                return false;
            }
        }
        
        return true;
    }
};