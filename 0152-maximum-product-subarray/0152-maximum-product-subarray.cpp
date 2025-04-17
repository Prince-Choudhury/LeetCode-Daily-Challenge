class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();

        int maxi = INT_MIN;

        int pref = 1;
        int suff = 1;

        for(int i = 0; i<n; i++){
            pref = pref * arr[i];
            suff = suff * arr[n-i-1];

            maxi = max({maxi, pref, suff});

            if(pref == 0){
                pref = 1;
            }

            if(suff == 0){
                suff = 1;
            }
        }

        return maxi;
    }
};