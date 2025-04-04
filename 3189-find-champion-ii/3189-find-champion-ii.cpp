class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        int ans = -1, count = 0;
        vector<int> indegree(n, 0);

        for(auto e: edges) indegree[e[1]]++;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {count++; ans = i; }
        }
        
        return count > 1?-1:ans;
        
    }
};