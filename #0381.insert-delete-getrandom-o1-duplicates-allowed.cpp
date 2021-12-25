class RandomizedCollection {
public:
    RandomizedCollection() {

        size = 0;
    }

    bool insert(int val) {

        nums.push_back(val);
        numsIndex[val].insert(size);
        size++;
        return numsIndex[val].size() == 1;
    }

    bool remove(int val) {

        if (numsIndex.count(val) == 0) {
            return false;
        }

        int last = nums.back();
        int id = size-1;
        if (last != val) {
            id = *(numsIndex[val].begin());
            numsIndex[last].erase(size-1);
            numsIndex[last].insert(id);
            nums[id] = last;
        }

        nums.pop_back();
        size--;
        numsIndex[val].erase(id);
        if (numsIndex[val].empty()) {
            numsIndex.erase(val);   
        }
        return true;
    }

    int getRandom() {
        
        return nums[random() %size];
    }

    private:
        vector<int> nums;
        unordered_map<int,unordered_set<int>> numsIndex;
        int size;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
