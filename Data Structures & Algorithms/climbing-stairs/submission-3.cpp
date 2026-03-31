class Solution {
public:
    int climbStairs(int n)
    {
        std::vector<int> myStairs(46, -1);
        myStairs[1] = 1;
        myStairs[2] = 2;
        myStairs[3] = 3;

        if (myStairs[n] != -1)
        {
            return myStairs[n];
        }

        for (int i = 4; i <= n; i++)
        {
            myStairs[i] = myStairs[i - 1] + myStairs[i - 2];
        }

        return myStairs[n];
    }
};

/*
    1 + 1 + 1 + 1
    1 + 1 + 2
    1 + 2 + 1
    2 + 1 + 1
    2 + 2
*/
