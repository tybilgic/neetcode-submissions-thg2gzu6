class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max = std::max_element(piles.begin(), piles.end());
        long long sum = std::accumulate(piles.begin(), piles.end(), 0);
        long long low = sum / h;
        if (sum % h)
            low++;
        long long high = *max;

        auto timeToEatAll = [&piles] (long long speed) {
            long long totalTime = 0;
            for (auto p : piles)
            {
                totalTime += p / speed;
                if (p % speed)
                    totalTime++;
            }
            return totalTime;
        };

        int result = 1000000000;
        while (low <= high)
        {
            long long speed = low + (high - low) / 2;
            long long time = timeToEatAll(speed);

            if (time > h)
            {
                low = speed + 1;
            }
            else
            {
                high = speed - 1;
                if (speed < result)
                    result = speed;
            }
        }

        return result;
    }
};
