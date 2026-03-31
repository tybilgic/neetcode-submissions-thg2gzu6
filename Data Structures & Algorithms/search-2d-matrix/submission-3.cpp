class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int up = 0;
        int down = m - 1;

        int idx;
        while (up <= down)
        {
            idx = up + (down - up) / 2;
            int low = matrix[idx][0];
            int high = matrix[idx][n - 1];

            // cout << "1 idx = " << idx << " low = " << low << " high = " << high << endl;
            if (low == target || high == target)
            {
                return true;
            }
            else if (target > high)
            {
                up = idx + 1;
            }
            else if (target < low)
            {
                down = idx - 1;
            }
            else
            {
                break;
            }
        }



        int left = 0;
        int right = n - 1;
        auto& row = matrix[idx];

        while (left <= right)
        {
            idx = left + (right - left) / 2;
            int val = row[idx];

            // cout << "2 idx = " << idx << " val = " << val << endl;

            if (val == target)
            {
                return true;
            }
            else if (val < target)
            {
                left = idx + 1;
            }
            else
            {
                right = idx - 1;
            }
        }

        return false;
    }
};
