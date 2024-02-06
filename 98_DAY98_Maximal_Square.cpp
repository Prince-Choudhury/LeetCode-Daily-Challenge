class Solution {
public: 
    int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi) {
        //base case
        if(i >= row || j>= col) {
            return 0;
        }

        //explore all 3 directions
        int right = solve(matrix, i, j+1, row, col, maxi);
        int diagnol = solve(matrix, i+1, j+1, row, col, maxi);
        int down = solve(matrix, i+1, j, row, col, maxi);

        //check can we build sqaure form current position
        if(matrix[i][j] == '1') {
            int ans = 1 + min(right, min(down, diagnol));
            //cout << "For i: " << i << "j: " << j << endl;
            //ye important hai 
            maxi = max(maxi, ans);
            return ans;

        }
        else {
            //agar 0 pr hi khade ho toh answer bhi zero hga
            return 0;
        }
     }
    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0; 
        int j = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        int ans = solve(matrix, i, j, row, col, maxi) ;
        return maxi*maxi;
    }
};