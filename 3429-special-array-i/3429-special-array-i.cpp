class Solution {
public:
    void solve(vector<int>&arr, vector<pair<int, int>>&p){
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(i+1<n){
                p.push_back(make_pair(arr[i], arr[i+1]));
            }
            
        }
    }
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return true;
        }

        vector<pair<int, int>>p;
        solve(nums, p);

        for(auto i : p){
            if((i.first & 1) && (i.second & 1)){
                return false;
            }

            if((i.first % 2 == 0) && (i.second % 2 == 0)){
                return false;
            }

        }

        return true;
    }
};