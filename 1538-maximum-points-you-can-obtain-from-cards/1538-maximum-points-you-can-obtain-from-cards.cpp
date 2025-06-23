class Solution {
public:
    int maxScore(vector<int>& arr, int k) {

        int sum = 0;

        int maxi = 0;

        for(int i = 0; i<k; i++){
            sum+= arr[i];
        }

        maxi = sum;

        int n = arr.size();

        int l = k-1;
        int r = n-1;

        while(k-- && r>=0){
            sum = sum - arr[l];
            l--;
            sum = sum + arr[r];
            r--;

            maxi = max(maxi, sum);
        }


        return maxi;
        
    }
};