class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (auto s : stones)
        {
            pq.push(s);
        }

        while (pq.size() > 1)
        {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            int res = abs(s1 - s2);

            if (res)
            {
                pq.push(res);
            }
        }
            
        if (pq.size() == 1)
        {
            return pq.top();
        }
        return 0;
    }
};
