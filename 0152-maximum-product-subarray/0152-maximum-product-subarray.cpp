class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();

        int maxi = INT_MIN;

        int product = 1;

        for(auto i : arr){
            product = product* i;
            maxi = max(maxi, product);

            if(product == 0){
                product = 1;
            }
        }

        product = 1;

        for(int i = n-1; i>=0; i--){
            product = product * arr[i];

            maxi = max(maxi, product);

            if(product == 0){
                product = 1;
            }
        }

        return maxi;
    }
};