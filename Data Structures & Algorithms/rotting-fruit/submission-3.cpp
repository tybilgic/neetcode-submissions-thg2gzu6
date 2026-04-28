class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                else if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        if (fresh == 0)
        {
            return 0;
        }

        int elapsed = 0;
        vector<pair<int, int>> neighbors = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while (!q.empty())
        {
            elapsed++;
            int qSize = q.size();
            for (int x = 0; x < qSize; x++)
            {
                auto [i, j] = q.front();
                q.pop();

                for (auto [di, dj] : neighbors)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni < 0 || ni >= rows ||
                        nj < 0 || nj >= columns ||
                        grid[ni][nj] != 1)
                    {
                        continue;
                    }
                    fresh--;
                    q.push({ni, nj});
                    grid[ni][nj] = 2;
                }
            }

            if (fresh <= 0)
            {
                return elapsed;
            }
        }

        return -1;
    }
};
