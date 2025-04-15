class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        if(numRows == 0){
            return ans;
        }

        ans.push_back({1});
        if(numRows == 1){
            return ans;
        }

        for(int i = 1; i<numRows; i++){
            vector<int>temp(i+1, 1);

            vector<int>arr = ans[i-1];

            for(int j = 1; j<i; j++){
                temp[j] = arr[j] + arr[j-1];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};