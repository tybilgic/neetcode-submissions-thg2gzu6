class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = arr.back();
        vector<int> res = arr;

        for (int i = arr.size() - 1; i > 0; i--)
        {
            res[i] = max;
            if (arr[i] > max)
                max = arr[i];
        }

        res[0] = max;
        res.back() = -1;

        return res;
    }
};