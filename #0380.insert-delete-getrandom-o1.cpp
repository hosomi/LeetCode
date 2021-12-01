class RandomizedSet {
public:
    RandomizedSet() {
        
    }

    bool insert(int val) {

        pair<set<int>::iterator, bool> result = s.insert(val);
        return result.second;
    }

    bool remove(int val) {

        if(s.find(val) == s.end()){
            return false;
        }
        s.erase(val);
        return true;
    }

    int getRandom() {

        set<int>::iterator it = s.begin();
        advance(it, rand() % s.size());
        return *it;
    }

private:
    set<int> s;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
