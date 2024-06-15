class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hashmap;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int GET(int key) {
        if (hashmap.find(key) == hashmap.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, hashmap[key]);
        return hashmap[key]->second;
    }

    void SET(int key, int value) {
        if (hashmap.find(key) != hashmap.end()) {
            cache.splice(cache.begin(), cache, hashmap[key]);
            hashmap[key]->second = value;
            return;
        }
        
        if (cache.size() == capacity) {
            int lru_key = cache.back().first;
            cache.pop_back();
            hashmap.erase(lru_key);
        }

        cache.emplace_front(key, value);
        hashmap[key] = cache.begin();
    }
};
