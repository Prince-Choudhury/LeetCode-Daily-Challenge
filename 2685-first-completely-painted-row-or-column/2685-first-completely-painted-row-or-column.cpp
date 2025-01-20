class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> mpr, mpc, mprc, mpcc;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j< mat[0].size(); ++j){
                mpr[mat[i][j]] = i;     mpc[mat[i][j]] = j;
            }
        }
        for(int i = 0; i < arr.size(); i++){
            int n = arr[i];
            mprc[mpr[n]]++;    mpcc[mpc[n]]++;
            if(mprc[mpr[n]] == mat[0].size() || mpcc[mpc[n]] == mat.size()) return i;
        }
        return -1;
    }
};