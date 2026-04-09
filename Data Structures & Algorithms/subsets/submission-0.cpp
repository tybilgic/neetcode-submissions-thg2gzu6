class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int>& nums, int idx)
    {
        res.push_back(path);
        for (int i = idx; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtrack(nums, i+1);
        }
        path.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
