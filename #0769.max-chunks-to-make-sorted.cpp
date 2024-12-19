class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int max = 0;
        int chunks = 0;
        for (int i = 0; i < arr.size(); i++) {
            max = std::max(max, arr[i]);
            if (max == i) {
                chunks++;
            }
        }
        return chunks;
    }
};
