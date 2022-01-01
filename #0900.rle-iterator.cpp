class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {

        v = encoding;
        index = 0;
    }

    int next(int n) {

        int size = v.size();
        while (index < size) {
            if (v[index]>=n) {
                v[index]-=n;
                return v[index+1];
            } else {
                n -= v[index];
                index += 2;
            }
        }
        return -1;
    }

private:
    int index;
    vector<int> v;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
