class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (_map.find(key) == _map.end()) {
            return -1;
        }
        else {
            _list.splice(_list.end(), _list, _map[key]);
            return (*_map[key]).second;
        }
    }
    
    void put(int key, int value) {
        if (_map.find(key) != _map.end()) {
            (*_map[key]).second = value;
            _list.splice(_list.end(), _list, _map[key]);
        } 
        else {
            _list.emplace_back(key, value);
            _map[key] = std::prev(_list.end());
        }

        if (_list.size() > _capacity) {
            std::pair<int, int> leastRecentlyUsed = _list.front();
            _map.erase(leastRecentlyUsed.first);
            _list.pop_front();
        }
    }

private: 
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> _map;
    std::list<pair<int, int>> _list;
    int _capacity;
};
