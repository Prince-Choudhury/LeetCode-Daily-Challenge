class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int n = s.size();

        int zero = 0;
        for(int i=0; i<n-1; i++){
            if(s[i] == '0') zero++;
            int one=0;
            for(int j = i+1; j<n; j++){
                if(s[j] == '1'){
                    one++;
                }
            }
            ans = max(ans, one+zero);
        }
        return ans;
    }
};