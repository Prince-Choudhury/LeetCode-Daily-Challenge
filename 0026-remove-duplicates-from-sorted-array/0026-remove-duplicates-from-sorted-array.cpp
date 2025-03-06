class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        vector<int>ans;
        ans.push_back(arr[0]);
        int index = 0;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]!=ans[index]){
                ans.push_back(arr[i]);
                index++;
            }
        }

        int size = ans.size();
        arr = ans;
        return size;
    }
};