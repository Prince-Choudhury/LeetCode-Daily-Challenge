class Solution {
public:

    int solve(vector<int>arr, int index, int currXor){
        if(index==arr.size()){

            return currXor;
        }

        //Exclude
        int exclude = solve(arr, index+1, currXor);

        //Include
        int include = solve(arr, index+1, currXor^arr[index]);

        return exclude + include;

    }

    int subsetXORSum(vector<int>& arr) {

        return solve(arr, 0, 0);
    }
};