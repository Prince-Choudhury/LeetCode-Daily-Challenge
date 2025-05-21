class Solution {
public:
    void solve(vector<vector<int>>& arr, int i, int j) {
        int n = arr.size();

        int m = arr[0].size();

        for (int col = 0; col < m; col++) {
            arr[i][col] = 0;
        }

        for (int row = 0; row < n; row++) {
            arr[row][j] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int m = matrix[0].size();

        vector<vector<int>>arr = matrix;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    solve(arr, i, j);
                }
            }
        }

        matrix = arr;
    }
};