class Solution {
private:
    bool canMake(int k,vector<int>& nums,vector<vector<int>>& q){
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(int i=0;i<k;i++){
            int s=q[i][0];
            int e=q[i][1];
            int val=q[i][2];
            diff[s]-=val;
            diff[e+1]+=val;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum + nums[i] <= 0) continue;
            else return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       
        int s=0;
        int e=queries.size();
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            bool can=canMake(mid,nums,queries);
            if(can){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};