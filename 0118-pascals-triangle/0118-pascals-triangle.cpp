class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if (numRows == 0) return ans;

        ans.push_back({1}); 

        for (int i = 1; i < numRows; i++) {
            vector<int> temp(i + 1, 1); 
            vector<int> prev = ans[i - 1];

            for (int j = 1; j < i; j++) {
                temp[j] = prev[j - 1] + prev[j];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};