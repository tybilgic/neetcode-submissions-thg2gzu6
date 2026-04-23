class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        myRows = grid.size();
        myColumns = grid[0].size();
        for (int i = 0; i < myRows; i++)
        {
            for (int j = 0; j < myColumns; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || i >= myRows ||
            j < 0 || j >= myColumns ||
            grid[i][j] == '0')
        {
            return;
        }
        
        grid[i][j] = '0';

        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

private:
    int myRows = 0;
    int myColumns = 0;
};
