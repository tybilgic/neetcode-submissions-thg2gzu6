class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
        {
            return -1;
        }

        int myRows = grid.size();
        int myColumns = grid[0].size();
        int distance = 0;
        queue<pair<int, int>> myQueue;
        vector<vector<int>> myVisited(myRows, vector<int>(myColumns));

        vector<pair<int, int>> deltas = {{-1, -1}, {-1, 0}, {-1, 1},
                                  {0, -1}, {0, 1},
                                  {1, -1}, {1, 0}, {1, 1}};

        myQueue.push(pair<int, int>{0, 0});
        myVisited[0][0] = 1;
        distance++;

        while (!myQueue.empty())
        {
            int qSize = myQueue.size();

            for (int x = 0; x < qSize; x++)
            {
                auto [i, j] =  myQueue.front();
                myQueue.pop();
                // cout << "node " << i << ", " << j << endl;
                if (i == (myRows - 1) && j == (myColumns - 1))
                {
                    return distance;
                }   
                

                for (int y = 0; y < deltas.size(); y++)
                {
                    auto [di, dj] = deltas[y];
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < 0 || ni >= myRows ||
                        nj < 0 || nj >= myColumns ||
                        grid[ni][nj] ||
                        myVisited[ni][nj])
                    {
                        continue;
                    }

                    myQueue.push({ni, nj});
                    myVisited[ni][nj] = 1;
                }
            }

            distance++;
        }

        
        return -1;
    }
};