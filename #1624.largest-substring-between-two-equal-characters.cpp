class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        int size = s.size();
        unordered_map<char, int> um;
        int result = -1;
        for (int i = 0; i < size; i++) {
            if (um.count(s[i]) > 0) {
                result = std::max(result, i - 1 - um[s[i]]);
            } else {
                um[s[i]] = i;
            }
        }
        return result;
    }
};
