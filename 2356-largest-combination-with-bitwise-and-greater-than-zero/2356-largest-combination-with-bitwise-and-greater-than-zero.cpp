class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> v(32,0);
        int ans = 0,x,j;
        for(auto &i: candidates){
            for(j = 0; j <= 31; j++){
                if(i&(1<<j)){
                    v[j]++;
                }
                ans = max(ans,v[j]);
            }
        }
        return ans;
    }
};