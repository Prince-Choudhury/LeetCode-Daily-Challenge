class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>arr;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid.size(); j++){
                arr.push_back(grid[i][j]);
            }
        }

        vector<int>ans;

        sort(arr.begin(), arr.end());

        for(int i = 0; i<arr.size()-1; i++){
            if(arr[i] == arr[i+1]){
                ans.push_back(arr[i]);
            }
        }

        bool isTrue = false;
        for(int i = 0; i<arr.size()-1; i++){
            if(abs(arr[i] - arr[i+1]) == 2){
                isTrue = true;
                ans.push_back(arr[i]+1);
            }
        }

        int n = arr.size();
        int m = grid.size();

        if(isTrue == false && arr[n-1] != m*m){
            ans.push_back(arr[arr.size()-1]+1);
        }
        
        if(isTrue == false && arr[n-1] == m*m){
            ans.push_back(1);
        }

        return ans;
    }
};