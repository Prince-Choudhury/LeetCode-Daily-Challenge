class Solution {
public:

    void solve(vector<int>& arr, int&ans1, int&ans2){

        for(int i = 0; i<arr.size(); i++){
            int len = 1;
            for(int j = i+1; j<arr.size(); j++){
                if(arr[j]>arr[j-1]){
                    len++;
                }
                else{
                    break;
                }
            }

            ans1 = max(ans1, len);
        }

        for(int i = 0; i<arr.size(); i++){
            int len = 1;
            for(int j = i+1; j<arr.size(); j++){
                if(arr[j]<arr[j-1]){
                    len++;
                }
                
                else{
                    break;
                }
            }

            ans2 = max(ans2, len);
        }
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans1 = -1;
        int ans2 = -1;
        solve(nums, ans1, ans2);

        return max(ans1, ans2);
    }
};