class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        int m = matrix.size();     // No. of rows
        int n = matrix[0].size();  // No. of col

        int count = 0;
        int Total = m*n;  // Total no of elements

        int startrow = 0;
        int endrow = m-1;
        int startcol = 0;
        int endcol = n-1;

        while(count<Total){

            for(int i = startcol; count<Total && i<=endcol; i++){
                count++;
                ans.push_back(matrix[startrow][i]);
            }
            startrow++;



            for(int i = startrow; count<Total && i<=endrow; i++){
                count++;
                ans.push_back(matrix[i][endcol]);
            }
            endcol--;


            for(int i = endcol; count<Total && i>=startcol; i--){
                count++;
                ans.push_back(matrix[endrow][i]);
            }
            endrow--;



            for(int i = endrow; count<Total && i>=startrow; i--){
                count++;
                ans.push_back(matrix[i][startcol]);
            }
            startcol++;
        }

        return ans;

    }
};