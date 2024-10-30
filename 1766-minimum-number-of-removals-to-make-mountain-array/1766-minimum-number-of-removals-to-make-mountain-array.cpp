class Solution {
public:
    
    int LIS(vector<int>&nums,vector<int>&dp1){
        int n=nums.size();
        vector<int> store;
        store.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]> store.back()) store.push_back(nums[i]);
            else{
                int lb= lower_bound(store.begin(),store.end(),nums[i]) -store.begin();
                store[lb]=nums[i];
            }
            dp1[i]= store.size();
        }
        int ans=store.size();
        return ans;
    }

    int LDS(vector<int>&nums,vector<int>&dp2){
        int n=nums.size();
        vector<int> store;
        store.push_back(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            if(nums[i]> store.back()) store.push_back(nums[i]);
            else{
                int lb= lower_bound(store.begin(),store.end(),nums[i]) -store.begin();
                store[lb]=nums[i];
            }
            dp2[i]= store.size();
        }
        int ans=store.size();
        return ans;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,0);
        int lis= LIS(nums,dp1);

        vector<int> dp2(n,0);
        int lds= LDS(nums,dp2);

        int maxi=-1;
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1){
                maxi=max(maxi,dp1[i]+dp2[i]);
            }
        }
        return n-maxi+1;
    }
};