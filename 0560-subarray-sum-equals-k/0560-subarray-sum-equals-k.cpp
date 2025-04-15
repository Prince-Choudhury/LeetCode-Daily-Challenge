class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_map<int, int>mpp;

        int count = 0;

        int sum = 0;
        
        for(int i = 0; i<n; i++){
            sum += arr[i];

            if(sum == k){
                count++;
            }

            int rem = sum - k;

            if(mpp.find(rem)!= mpp.end()){
                count+=mpp[rem];
            }

            mpp[sum]++;
        }

        return count;
    }
};