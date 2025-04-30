class Solution {
public:
    int findNumbers(vector<int>& arr) {
        int ans = 0;
        for(auto i : arr){
            string s = to_string(i);
            int n = s.size();
            
            if(n % 2 == 0){
                ans++;
            }
        }

        return ans;
    }
};