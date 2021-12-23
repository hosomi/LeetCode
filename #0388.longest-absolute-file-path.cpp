class Solution {
public:
    int lengthLongestPath(string input) {

        int size = input.size();
        int result = 0;
        int index = 0;
        map<int, int> m {{0, 0}};
        for (int i = 0; i < size; ++i) {
            int start = i;
            while (i < size && input[i] != '\n' && input[i] != '\t') {
                ++i;
            }
            if (i >= size || input[i] == '\n') {
                string s = input.substr(start, i - start);
                if (s.find('.') != string::npos) {
                    result = std::max(result, m[index] + (int)s.size());
                } else {
                    ++index;
                    m[index] = m[index - 1] + (int)s.size() + 1;
                }
                index = 0;
            } else {
                ++index;
            }
        }
        return result;
    }
};
