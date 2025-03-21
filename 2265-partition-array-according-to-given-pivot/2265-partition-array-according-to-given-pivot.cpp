class Solution {
public:
   
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low=0,same=0,high=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ++low;
            }else if(nums[i]==pivot)
                ++same;
        }
        high=low+same;
        same=low;
        low=0;
        vector<int>res(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                res[low++]=nums[i];
            }else if(nums[i]==pivot){
                res[same++]=nums[i];
            }else{
                res[high++]=nums[i];
            }
        }
        return res;
        
    }
};