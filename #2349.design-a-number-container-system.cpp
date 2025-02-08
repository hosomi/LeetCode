class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (m[index]) {
            s[m[index]].erase(index);
        }

        m[index] = number;
        s[number].insert(index); 
    }
    
    int find(int number) {
        return s[number].size() ? *s[number].begin() : -1;
    }

private:
    unordered_map<int, int> m;
    unordered_map<int, set<int>> s;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
