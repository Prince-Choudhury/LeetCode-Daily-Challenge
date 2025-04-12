class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int>ans;
        int n = arr.size();
        unordered_map<int, int>mpp;
        for(int i = 0; i<arr.size(); i++){
            mpp[arr[i]]++;
        }

        for(auto i : mpp){
            if(i.second>n/3){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};