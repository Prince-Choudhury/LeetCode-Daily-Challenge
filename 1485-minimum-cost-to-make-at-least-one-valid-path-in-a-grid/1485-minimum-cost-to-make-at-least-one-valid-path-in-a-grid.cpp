class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 

        pq.push({0, 0, 0}); 
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0], i = curr[1], j = curr[2];

            if (visited[i][j]) continue;
            visited[i][j] = true;
            if (i == n - 1 && j == m - 1) return cost;
            for (int d = 0; d < 4; ++d) {
                int ni = i + directions[d].first;
                int nj = j + directions[d].second;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int newCost = cost + (grid[i][j] != d + 1 ? 1 : 0); 
                    pq.push({newCost, ni, nj});
                }
            }
        }
        return -1; 
    }
};