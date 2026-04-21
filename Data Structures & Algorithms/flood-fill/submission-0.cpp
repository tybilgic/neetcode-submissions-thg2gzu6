class Solution {
public:
    using Matrix = vector<vector<int>>;
    void fill(Matrix& image, int r, int c)
    {
        if (min(r, c) < 0 ||
            r == myRows || c == myColumns ||
            myVisited[r][c] ||
            image[r][c] != myOriginalColor)
        {
            return;
        }

        image[r][c] = myFillColor;

        myVisited[r][c] = 1;

        fill(image, r + 1, c);
        fill(image, r - 1, c);
        fill(image, r, c + 1);
        fill(image, r, c - 1);

        myVisited[r][c] = 0;
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        myOriginalColor = image[sr][sc];
        myFillColor = color;
        myRows = image.size();
        myColumns = image[0].size();

        myVisited = Matrix(myRows, vector<int>(myColumns, 0));

        fill(image, sr, sc);

        return image;
    }
private:
    int myOriginalColor = 0;
    int myFillColor = 0;
    int myRows = 0;
    int myColumns = 0;
    Matrix myVisited;
};