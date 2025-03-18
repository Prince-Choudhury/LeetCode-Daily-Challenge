class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k% n;

        //Entire array
        reverse(arr.begin(), arr.end()); 

        reverse(arr.begin(), arr.begin()+k);

        reverse(arr.begin()+k, arr.end());
    }
};