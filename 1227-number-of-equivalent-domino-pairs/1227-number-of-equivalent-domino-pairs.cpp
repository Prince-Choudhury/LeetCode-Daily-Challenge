class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans=0;
        map<vector<int>,int> m;
        for(auto i:dominoes)
        {
            sort(i.begin(),i.end());
            if(m.find(i)!=m.end()) ans+=m[i]++;
            else m[i]++;
        }
        return ans;
    }
};