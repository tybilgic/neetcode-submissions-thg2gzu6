class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(46);

        vec[1] = 1;
        vec[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            vec[i] = vec[i - 1] + vec[i - 2];
        }

        return vec[n];
    }
};
