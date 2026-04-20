class LRUCache {
public:
    using Entry = pair<int, int>;
    LRUCache(int capacity) {
        myCapacity = capacity;
    }
    
    int get(int key) {
        auto it = myLruMap.find(key);

        if (it == myLruMap.end())
        {
            return -1;
        }

        auto& entryIt = it->second;
        refreshLruEntry(entryIt);
        return entryIt->second;
    }
    
    void put(int key, int value) {
        auto it = myLruMap.find(key);

        if (it == myLruMap.end())
        {
            myLruList.emplace_front(key, value);
            myLruMap[key] = myLruList.begin();

            if (myLruMap.size() > myCapacity)
            {
                evictLru();
            }
        }
        else
        {
            it->second->second = value;
            refreshLruEntry(it->second);
        }
    }

private:
    void evictLru()
    {
        auto lruEntryKey = myLruList.back().first;
        myLruMap.erase(lruEntryKey);
        myLruList.pop_back();
    }

    void refreshLruEntry(list<Entry>::iterator& entryIt)
    {
        myLruList.splice(myLruList.begin(), myLruList, entryIt);
    }

private:
    unordered_map<int, list<Entry>::iterator> myLruMap;
    list<Entry> myLruList;
    int myCapacity;
};
