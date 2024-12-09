class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> bad;
        vector<bool> ans;
        int n = nums.size();

        bad.push_back(0);
        for(int i=1 ; i<n ; i++){
            if(nums[i]%2==nums[i-1]%2){
                bad.push_back(1);
            }else{
                bad.push_back(0);
            }
        }

        vector<int> pSum(n);
        pSum[0] = 0;
        for(int i=1 ; i<n ; i++){
            pSum[i] = pSum[i-1]+bad[i];
        }

        for(int i=0 ; i<queries.size() ; i++){

            int l = queries[i][0];
            int r = queries[i][1];

            if(pSum[r]-pSum[l] >= 1) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};