class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        int size = s.size();
        if (s.empty() || size < 10) {
            return {};
        }

        vector<string> result;
        map<string, int> m;
        string sequence;
        for(decltype(size) i = 0; i < size - 9; ++i) {
            sequence = s.substr(i, 10);
            ++m[sequence];
        }

        for (auto i : m) {
            if (i.second > 1) {
                result.push_back(i.first);
            }
        }
        return result;
    }
};
