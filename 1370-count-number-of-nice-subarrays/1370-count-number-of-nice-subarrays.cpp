class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int k) {
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] % 2 == 0){
                arr[i] = 0;
            }
            else{
                arr[i] = 1;
            }
        }

        int ans = 0;
        int sum = 0;
        unordered_map<int, int>mpp;

        for(int i = 0; i<arr.size(); i++){
            sum+=arr[i];

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