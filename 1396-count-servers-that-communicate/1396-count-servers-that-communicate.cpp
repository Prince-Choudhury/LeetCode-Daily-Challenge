class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> visR(r,0);
        vector<int> visC(c,0);
        int ans = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    visR[i]++;
                    visC[j]++;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && (visR[i]>1 || visC[j]>1)) ans++;
            }
        }
        return ans;
    }
};