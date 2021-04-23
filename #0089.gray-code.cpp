class Solution {
public:
    vector<int> grayCode(int n) {

        vector<int> result = {0};
        int sequence;
        int resize;
        for (int i = 0; i < n; ++i) {
            sequence = 1 << i;
            resize = result.size() -1;
            for (int j = resize; j >= 0; --j) {
                result.push_back(sequence + result[j]);
            }
        }
        return result;
    }
};
