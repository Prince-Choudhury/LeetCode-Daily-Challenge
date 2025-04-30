class Solution {
public:
    int findNumbers(vector<int>& arr) {
        int ans = 0;
        for(auto i : arr){
            string s = to_string(i);
            int count = 0;
            for(int i = 0; i<s.size(); i++){
                count++;
            }

            if(count%2 == 0){
                ans++;
            }
        }

        return ans;
    }
};