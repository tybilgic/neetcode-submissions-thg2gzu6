class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int maxOnes = 0;

        for (auto num : nums)
        {
            if (num == 0)
            {
                if (ones > maxOnes)
                    maxOnes = ones;

                ones = 0;
            }
            else
            {
                ones++;
            }

        }

        if (ones > maxOnes)
            maxOnes = ones;

        return maxOnes;
    }
};