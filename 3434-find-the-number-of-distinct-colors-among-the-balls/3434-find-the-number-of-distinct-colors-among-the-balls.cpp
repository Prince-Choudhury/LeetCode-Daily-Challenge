class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> ballsColor, uniqueColors;
        int n= queries.size();
        vector<int> ans(n,0);
        for(int i =0;i<n;i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ballsColor[ball])
            {
                if(uniqueColors[ballsColor[ball]] == 1)
                {
                    uniqueColors.erase(ballsColor[ball]);
                }else{
                    uniqueColors[ballsColor[ball]]--;
                }
                
            }
            ballsColor[ball] = color;
            uniqueColors[color]++;
            ans[i] = uniqueColors.size();
        }
        return ans;
    }
};