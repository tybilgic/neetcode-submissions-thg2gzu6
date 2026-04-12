class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        myK = k;

        for (auto n : nums)
        {
            myPrioQ.push(n);
        }
    }
    
    int add(int val) {
        myPrioQ.push(val);
        vector<int> temp;

        for (int i = 0; i < myK; i++)
        {
            temp.push_back(myPrioQ.top());
            myPrioQ.pop();
        }

        for (auto t : temp)
        {
            myPrioQ.push(t);
        }

        return temp.back();
    }

private:
    priority_queue<int> myPrioQ;
    int myK;
};
