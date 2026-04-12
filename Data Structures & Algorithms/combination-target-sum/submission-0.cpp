class Solution {
public:
    vector<int> myComb;
    vector<vector<int>> myRes;
    int myTarget = 0;
    void backtrack(vector<int>& nums, int sum, int start)
    {
        if (sum == myTarget)
        {
            myRes.push_back(myComb);
        }
        else if (sum < myTarget)
        {
            for (int i = start; i < nums.size(); i++)
            {
                int num = nums[i];
                myComb.push_back(num);
                backtrack(nums, sum + num, i);
            }
        }
        myComb.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        myTarget = target;
        backtrack(nums, 0, 0);
        return myRes;
    }
};
