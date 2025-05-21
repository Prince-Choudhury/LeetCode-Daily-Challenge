class Solution {
public:
   
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int m = matrix[0].size();

        vector<pair<int, int>>arr;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    arr.push_back(make_pair(i,j));
                }
            }
        }

        for(auto i : arr){
            int row = i.first;
            for(int col = 0; col<m; col++){
                matrix[row][col] = 0;
            }
        }

        for(auto i : arr){
            int col = i.second;
            for(int row = 0; row<n; row++){
                matrix[row][col] = 0;
            }
        }
    }
};