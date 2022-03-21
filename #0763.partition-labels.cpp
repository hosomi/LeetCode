class Solution {
public:
    vector<int> partitionLabels(string s) {

        int length = s.length();
        int labels[26];
        for (int i = 0; i < length; ++i) {
            labels[s[i] - 'a'] = i;
        }

        int j = 0;
        int label = 0;
        vector<int> result;
        for (int i = 0; i < length; ++i) {
            j = max(j, labels[s[i] - 'a']);
            if (i == j) {
                result.push_back(i - label + 1);
                label = i + 1;
            }
        }
        return result;
    }
};
