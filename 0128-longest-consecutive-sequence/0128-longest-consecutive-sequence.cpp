class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int m = nums.size();
        
        if(m == 0){
            return 0;
        }
        set<int>st;
        for(auto i: nums){
            st.insert(i);
        }

        vector<int>arr;

        for(auto i : st){
            arr.push_back(i);
        }

        int n = arr.size();

        int cnt = 0;
        int maxiCnt = 0;
        for(int i = 0; i<n-1; i++){
            if(abs(arr[i+1] - arr[i]) == 1){
                cnt++;
                if(maxiCnt<cnt){
                    maxiCnt = cnt;
                }
            }
            else{
                cnt = 0;
            }


        }

        return maxiCnt+1;
    }
};