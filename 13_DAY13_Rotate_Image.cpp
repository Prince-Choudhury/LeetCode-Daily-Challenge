class Solution {
public:

    void reverseVector(vector<int>& arr){
        int n = arr.size();
        int start = 0;
        int end = n-1;
        while(start<end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //Transpose the matrix
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //Reverse the matrix
        for(int i=0; i<n; i++)
        {
            //reverse(matrix[i].begin(), matrix[i].end());
            reverseVector(matrix[i]);
        }
    }
};