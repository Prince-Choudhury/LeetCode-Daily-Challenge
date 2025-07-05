class Solution {
public:
    int solve(vector<int>& arr, int k) {
        int ans = 0;
        int l = 0;
        unordered_map<int, int>mpp;

        for(int r = 0; r<arr.size(); r++){
            mpp[arr[r]]++;

            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0){
                    mpp.erase(arr[l]);
                }
                l++;
            }

            ans = ans + r-l+1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return solve(arr, k) - solve(arr, k-1);
    }
};