class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<long long,long long>>vx,vy;
        for(auto it:rectangles)
        {
            vx.push_back({it[0],it[2]});
            vy.push_back({it[1],it[3]});
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        int cx=0,cy=0;
        long long cmpy=vy[0].second;
        for(auto it:vy) 
        {    
            if(cmpy<=it.first)
            {
                ++cy;
                cmpy=it.second;
            }
            else if(cmpy<it.second)
                cmpy=it.second;
        }
        if(cy>=2)
            return 1;
        long long cmpx=vx[0].second;
        for(auto it:vx) 
        {    
            if(cmpx<=it.first)
            {
                ++cx;
                cmpx=it.second;
            }
            else if(cmpx<it.second)
                cmpx=it.second;
        }
        if(cx>=2)
            return 1;
        return 0;
    }
};