class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int idx;
        int num;
        while (left <= right)
        {
            idx = (left + right) / 2;
            num = nums[idx];
            if (num == target)
            {
                return idx;
            }
            else if (num < target)
            {
                left = idx + 1;
            }
            else
            {
                right = idx - 1;
            }
        }

        return -1;
    }
};
