class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int j = 1;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]!=arr[i-1]){
                arr[j] = arr[i];
                j++;
            }
        }

        return j;
    }
};