class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total_sum=0;
        int n=matrix.size();
        int mini=INT_MAX;
        int cnt_neg=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                total_sum+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
                if(matrix[i][j]<0) cnt_neg++;
            }
        }
        if(cnt_neg%2==0){
            return total_sum;
        }else{
            return total_sum-2*mini;
        }
    }
};