class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        ans.resize(2 * n);
        int i = 0;

        for(auto num : nums)
        {
            ans[i] = num;
            ans[i + n] = num;
            i++;
        }

        return ans;
    }
};