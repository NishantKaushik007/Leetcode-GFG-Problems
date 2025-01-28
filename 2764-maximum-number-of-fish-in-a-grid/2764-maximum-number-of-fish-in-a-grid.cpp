class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int max_fish = 0;

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    int current_sum = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    current_sum += grid[i][j];
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        int r = p.first;
                        int c = p.second;

                        for (auto& dir : dirs) {
                            int nr = r + dir.first;
                            int nc = c + dir.second;

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                current_sum += grid[nr][nc];
                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                            }
                        }
                    }

                    max_fish = max(max_fish, current_sum);
                }
            }
        }
        return max_fish;
    }
};