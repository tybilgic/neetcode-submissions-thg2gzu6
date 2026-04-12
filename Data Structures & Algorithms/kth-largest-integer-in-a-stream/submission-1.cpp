class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        myK = k;

        for (auto n : nums)
        {
            add(n);
        }
    }
    
    int add(int val) {
        myPrioQ.push(val);
        
        if (myPrioQ.size() > myK)
        {
            myPrioQ.pop();
        }
        return myPrioQ.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> myPrioQ;
    int myK;
};
