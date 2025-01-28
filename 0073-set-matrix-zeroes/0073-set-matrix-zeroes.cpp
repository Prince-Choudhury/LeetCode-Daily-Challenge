class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int, int>>arr;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    arr.push_back(make_pair(i, j));
                }

            }
        }

        int size = arr.size();

        for(auto i : arr){
            int row = i.first;
            for(int c = 0; c<m; c++){
                matrix[row][c] = 0;
            }

            int col = i.second;
            for(int r = 0; r<n; r++){
                matrix[r][col] = 0;
            }
        }

        
    }
};