class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {

        auto at = mcache.find(key); 
        if (at == mcache.end()) {
            return -1;
        }

        auto work = *mcache[key]; 
        cache.erase(mcache[key]);
        cache.push_front(work);
        mcache[key] = cache.begin();
        return work.second;
    }

    void put(int key, int value) {

        auto at = mcache.find(key);
        if (at == mcache.end()) {
            if (cache.size() == size) {
                auto temp = cache.back();
                mcache.erase(temp.first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key,value));
            mcache[key] = cache.begin();
        } else {
            cache.erase(mcache[key]);
            cache.push_front(make_pair(key,value));
            mcache[key] = cache.begin();
        }
    }

private:
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> mcache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
