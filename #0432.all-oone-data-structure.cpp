class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        s.erase({m[key], key});
        m[key]++;
        s.insert({m[key], key});
    }
    
    void dec(string key) {
        s.erase({m[key], key});
        m[key]--;
        if (m[key] == 0) {
            m.erase(key);
        } else {
            s.insert({m[key], key});
        }
    }
    
    string getMaxKey() {
        return s.size()== 0 ? "" : s.rbegin()->second;
    }
    
    string getMinKey() {
        return s.size() == 0 ? "" : s.begin()->second;
    }

private:
    unordered_map<string, int> m;
    set<pair<int, string>> s;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
