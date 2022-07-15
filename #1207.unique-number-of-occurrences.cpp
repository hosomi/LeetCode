class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        map<int, int> mcount;
        for (int e : arr) {
            if (mcount.find(e) == mcount.end()) {
                mcount[e] = 1;
            } else {
                mcount[e]++;
            }
        }

        set<int> scount;
        for (map<int, int>::iterator it = mcount.begin(); it != mcount.end(); it++) {
            if (scount.find(it->second) == scount.end()) {
                scount.insert(it->second);
            } else {
                return false;
            }
        }

        return true;
    }
};
