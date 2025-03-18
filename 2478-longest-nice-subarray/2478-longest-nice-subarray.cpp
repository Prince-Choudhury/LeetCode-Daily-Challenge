class Solution {
public:
    
    int longestNiceSubarray(vector<int>& nums) {
        
        int i=0,j=0;
        int num = 0;
        int ans = 0;
    
        for(i=0;i<nums.size();i++){
            
            while((num&nums[i])!=0){

                num^=nums[j];
                
                j++;
            }
            
            num |= nums[i];
            
            ans = max(ans, i-j+1);
            
        }
        return ans;
        
    }
};