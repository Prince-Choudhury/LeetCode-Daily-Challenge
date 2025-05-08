class Solution {
public:
    int minTimeToReach(vector<vector<int>>&grid) {
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        
        //int cnt=0;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        pq.push({0,{0,0,0}});

        vector<vector<int>>temp(n,vector<int>(m,INT_MAX));
        temp[0][0]=0;
        while(!pq.empty())
            {
                auto it=pq.top();
                pq.pop();
                int curr=it.first;
                int x=it.second[0],y=it.second[1],cnt=it.second[2];
                if(x==n-1 && y==m-1)
                    return curr;
                for(int i=0;i<4;++i)
                    {
                        int nx=x+dir[i].first;
                        int ny=y+dir[i].second;
                        if(nx>=0 && nx<n && ny>=0 && ny<m)
                        {
                            int add=(cnt)?2:1;
                            int wait=max(curr,grid[nx][ny])+add;
                            if(wait<temp[nx][ny])
                            {
                                temp[nx][ny]=wait;
                                pq.push({wait,{nx,ny,1-cnt}});
                            }
                        }
                    }
            }
    return -1;
    }
};