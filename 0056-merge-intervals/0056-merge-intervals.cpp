class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>>ans;

        vector<int>temp = arr[0];

        for(int i = 1; i<arr.size(); i++){
            vector<int>a = arr[i];

            if(temp[1]>=a[0]){
                int ele = max(temp[1], a[1]);
                temp[1] = ele;
            }
            else{
                ans.push_back(temp);
                temp = a;
            }
        }

        ans.push_back(temp);

        return ans;

    }
};