class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int>mp;

        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }

        int ans = 0;

        for(auto i : mp){
            int n = i.second;
            if(n>1){
                ans+=(((n-1)*(n-1+1))/2) * 8;
            }
        }

        return ans;

    }
};