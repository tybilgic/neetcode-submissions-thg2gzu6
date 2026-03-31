class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        int last;
        int second_last;
        for (auto op : operations)
        {
            switch(op[0])
            {
                case '+':
                    last = record.back();
                    second_last = *(record.rbegin() + 1);
                    record.push_back(last + second_last);
                    break;
                case 'C':
                    record.pop_back();
                    break;
                case 'D':
                    record.push_back(record.back() * 2);
                    break;
                default:
                    // number
                    record.push_back(std::stoi(op));
                    break;
            }
        }

        int sum = 0;
        for (auto rec : record)
        {
            sum += rec;
        }

        return sum;
    }
};