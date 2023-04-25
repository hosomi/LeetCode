class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        
        for (int i = 1; i <= 1001; i++) {
            bag.insert(i);
        }
    }
    
    int popSmallest() {
        
        int num = *(bag.begin());
        bag.erase(bag.begin());
        return num;
    }
    
    void addBack(int num) {
        
        bag.insert(num);
    }

private:
    set<int> bag;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
