class Solution {
public:

    void solve(vector<int>arr, vector<vector<int>>&ans, int index, vector<int>output){
        if(index>=arr.size()){
            ans.push_back(output);
            return;
        }

        //Exclude
        solve(arr, ans, index+1, output);

        //Include
        int ele = arr[index];

        output.push_back(ele);
        solve(arr, ans, index+1, output);

    }

    void compute(vector<int>arr, int&sum){
        if(arr.empty()){
            sum = sum + 0;
        }

        if(arr.size() == 1){
            sum = sum + arr[0];
        }

        int Xor = 0;
        if(arr.size()>1){
            for(int i = 0; i<arr.size(); i++){
                Xor = Xor ^ arr[i];
            }
        }
        

        sum = sum + Xor;
    }

    int subsetXORSum(vector<int>& arr) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(arr, ans, 0, output);

        int sum = 0;
        for(int i = 0; i<ans.size(); i++){
            compute(ans[i], sum);
        }

        return sum;
    }
};