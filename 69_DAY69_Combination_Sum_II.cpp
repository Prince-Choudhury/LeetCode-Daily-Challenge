class Solution {
public:
    void findAns(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& helper) {
        if(target == 0) {
            ans.push_back(helper);
            return;
        }
        for(int i = index; i < arr.size(); i++) {
            if(i > index && arr[i] ==arr[i-1]) continue;
            if(arr[i] > target) break;
            helper.push_back(arr[i]);
            findAns(i+1, target-arr[i], arr, ans, helper);
            helper.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> helper;
        findAns(0, target, candidates, ans, helper);
        return ans;
    }
};