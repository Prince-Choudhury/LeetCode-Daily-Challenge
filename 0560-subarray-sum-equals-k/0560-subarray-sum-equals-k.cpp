

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int>mpp;
        
        int sum = 0;

        int ans = 0;
        
        for(int i = 0; i<arr.size(); i++){
            sum = sum + arr[i];
            if(sum == k){
                ans++;
            }
            
            int rem = sum - k;
            
            if(mpp.find(rem) != mpp.end()){
                ans += mpp[rem];
            }
            
            mpp[sum]++;
        }

        return ans;
    }
};