class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> setint;

        for (auto n : nums)
        {
            if (setint.count(n))
            {
                return true;
            }

            setint.insert(n);
        }

        return false;
    }
};