class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        set<vector<int>> st;

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int k = j+1;
                int l = n - 1;

                while(k<l){
                    long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                    if (sum == target) {
                        vector<int> arr1 = {arr[i], arr[j], arr[k], arr[l]};
        
                        if (st.find(arr1) == st.end()) {
                            ans.push_back(arr1);
                        }
                        st.insert(arr1);

                        k++;
                        l--;
                    }

                    else if(sum<target){
                        k++;
                    }

                    else{
                        l--;
                    }

                }
                        
            }
        }

        return ans;
    }
};