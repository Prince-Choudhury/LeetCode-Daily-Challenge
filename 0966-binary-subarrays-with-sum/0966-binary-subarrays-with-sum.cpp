
class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int>mpp;

        for(int i = 0; i<arr.size(); i++){
            sum = sum + arr[i];

            if(sum == k){
                ans++;
            }

            int rem = sum - k;

            if(mpp.find(rem) != mpp.end()){
                ans = ans + mpp[rem];
            }

            mpp[sum]++;
        }

        return ans;
    }
};