class Solution {
public:
    int maxProduct(vector<string>& words) {

        int size = words.size();
        if (size <= 1) {
            return 0;
        }

        vector<int> v(size, 0);
        for (int i = 0; i < size; ++i) {
            for (const char& c : words[i]) {
                v[i] |= 1 << (c - 'a');
            }
        }

        int result = 0;
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if ((v[i] & v[j]) == 0) {
                    result = std::max(result,
                        (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return result;
    }
};
