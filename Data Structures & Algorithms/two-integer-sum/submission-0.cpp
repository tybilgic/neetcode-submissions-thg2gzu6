class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;

        for (int idx = 0; idx < nums.size(); idx++)
        {
            int complement = target - nums[idx];

            auto it = hashMap.find(complement);
            if (it != hashMap.end())
            {
                return {it->second, idx};
            }

            hashMap[nums[idx]] = idx;
        }

        return {};
    }
};
