class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Distance matrix to track minimum obstacles removed
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[0][0] = 0;

        // Directions for moving in the grid
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                // Check if the neighbor is within bounds
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newDist = distance[x][y] + grid[nx][ny];

                    // If this path offers a smaller distance, update it
                    if (newDist < distance[nx][ny]) {
                        distance[nx][ny] = newDist;

                        // Push to deque based on the weight (0 for front, 1 for back)
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        return distance[m - 1][n - 1];
    }
};