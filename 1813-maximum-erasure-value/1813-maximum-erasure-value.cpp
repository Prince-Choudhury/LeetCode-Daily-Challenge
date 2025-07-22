class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int msum=0;
        int sum=0;
        unordered_set<int> s;
        int j=0,i=0;
        while(j<nums.size()){
            while(s.count(nums[j])){
                s.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            s.insert(nums[j]);
            sum+=nums[j];
            msum=max(msum,sum);
            j++;
        }
        return msum;
    }
};