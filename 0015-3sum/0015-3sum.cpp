class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        int n = arr.size();

        sort(arr.begin(), arr.end());

        set<vector<int>>st;

        vector<vector<int>>ans;

        for(int i = 0; i<n; i++){
            int j = i+1;
            int k = n-1;

            while(j<k){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum == 0){
                    vector<int>temp = {arr[i], arr[j], arr[k]};
                    if(st.find(temp) == st.end()){
                        ans.push_back(temp);
                    }

                    st.insert(temp);
                    j++;
                    k--;
                }

                else if(sum<0){
                    j++;
                }

                else{
                    k--;
                }
            }
        }

        return ans;

    }
};