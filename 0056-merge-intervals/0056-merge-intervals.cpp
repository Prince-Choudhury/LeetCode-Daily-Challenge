class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>>ans;

        vector<int>temp = arr[0];

        int a = arr[0][0];
        int b = arr[0][1];

        for(int i = 1; i<arr.size(); i++){
            int c = arr[i][0];
            int d = arr[i][1];

            if(b>=c){
                int ele = max(b, d);
                b = ele;
            }
            else{
                ans.push_back({a, b});
                a = c;
                b = d;
            }
        }

        ans.push_back({a,b});

        return ans;

    }
};