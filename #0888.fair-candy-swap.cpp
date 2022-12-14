class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {

        vector<int>& a = aliceSizes;
        vector<int>& b = bobSizes;
        int bSum = accumulate(b.begin(), b.end(), 0);
        int aHalf = (accumulate(a.begin(), a.end(), 0) + \
            accumulate(b.begin(), b.end(), 0)) / 2;
        int size = a.size();
        for (int i = 0; i < size; i++) {
            int toFind = bSum + a[i] - aHalf;
            vector<int>::iterator it = find(b.begin(), b.end(), toFind);
            if (it != b.end()) {
                return vector<int> {a[i], *it};
            }
        }
        return vector<int> {0,0};
    }
};
