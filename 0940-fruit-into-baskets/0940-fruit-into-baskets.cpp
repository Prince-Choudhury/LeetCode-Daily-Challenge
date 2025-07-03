class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int, int>hash;
        
        int diff = 0;
        int l = 0;

        int ans = 0;
        for(int r = 0; r<arr.size(); r++){
            if(hash[arr[r]] == 0){
                diff++;
            }

            while(diff>2){
                hash[arr[l]]--;
                if(hash[arr[l]] == 0){
                    diff--;
                }
                l++;
            }

            hash[arr[r]]++;

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};