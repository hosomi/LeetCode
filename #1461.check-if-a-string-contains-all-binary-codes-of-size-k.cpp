class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int size = s.size();
        set<string> result;
        for (int i = 0; i + k - 1 < size; i++) {
            result.insert(s.substr(i, k));
        }
        return result.size() == pow(2, k);
    }
};
