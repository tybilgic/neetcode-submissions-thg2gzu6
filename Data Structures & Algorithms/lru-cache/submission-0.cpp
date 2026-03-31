class LRUCache {
public:
    LRUCache(int capacity) : myCapacity(capacity) {
        myMap.reserve(capacity);
    }
    
    int get(int key) {
        auto it = myMap.find(key);
        if (it == myMap.end())
            return -1;
        
        myList.splice(myList.begin(), myList, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = myMap.find(key);

        if (it != myMap.end())
        {
            it->second->second = value;
            myList.splice(myList.begin(), myList, it->second);
            return;
        }

        if (myMap.size() == myCapacity)
        {
            int lruKey = myList.back().first;
            myMap.erase(lruKey);
            myList.pop_back();
        }

        myList.emplace_front(key, value);
        myMap[key] = myList.begin();
    }

private:
    using Node = std::pair<int, int>;
    using NodeList = std::list<Node>;
    int myCapacity = 0;
    std::list<Node> myList;
    std::unordered_map<int, NodeList::iterator> myMap;
};
