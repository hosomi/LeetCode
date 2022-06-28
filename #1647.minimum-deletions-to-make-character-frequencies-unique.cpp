class Solution {
public:
    int minDeletions(string s) {

        std::array<int, 26> freq{};
        for (char c : s) {
            ++freq[c - 'a'];
        }

        std::sort(freq.begin(), freq.end(), greater<int>());
        int keep = 0, prev = INT_MAX;
        for (int f : freq) {
            if (!f || !prev) {
                break;
            }
            prev = std::min(f, prev - 1);
            keep += prev;
        }
        return s.size() - keep;
    }
};
