class Solution {
public:
    using Point = pair<int, double>;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const Point& a, const Point& b) {
            return a.second > b.second;
        };
        priority_queue<Point, vector<Point>, decltype(cmp)> pq;
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            double dist = sqrt(x * x + y * y);

            pq.push(Point(i, dist));
        }

        vector<vector<int>> res;

        for (int i = 0; i < k; i++)
        {
            auto& idx = pq.top().first;
            res.push_back({points[idx][0], points[idx][1]});
            pq.pop();
        }

        return res;
    }
};
