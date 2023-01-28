class MapSum {
public:
    MapSum() {

        m.clear();
    }
    
    void insert(string key, int val) {
        
        m[key] = val;
    }
    
    int sum(string prefix) {
        
        int size = prefix.size();
        int total = 0;
        for (auto it = m.lower_bound(prefix); it != m.end(); it++) {
            if (prefix == it->first.substr(0, size)) {
                total += it->second;
            } else {
                break;
            }
        }
        return total;
    }

private:
    map<string, int> m;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
