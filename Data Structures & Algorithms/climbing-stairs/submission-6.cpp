class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        else if (myMemo.find(n) != myMemo.end())
            return myMemo[n];

        myMemo[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return myMemo[n];
    }

private:
    unordered_map<int, int> myMemo;
};
