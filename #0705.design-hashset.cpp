class MyHashSet {
public:
    MyHashSet() {
        
    }
    
    void add(int key) {

        if (!contains(key)) {
            v.push_back(key);
        }
    }
    
    void remove(int key) {

        if (contains(key)) {
            v.erase(find(v.begin(), v.end(), key));
        }
    }
    
    bool contains(int key) {
        return find(v.begin(), v.end(), key) != v.end();
    }

private:
    vector<int> v;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
