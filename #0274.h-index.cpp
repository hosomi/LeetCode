class Solution {
public:
    int hIndex(vector<int>& citations) {

        int size = citations.size();
        std::sort(citations.begin(), citations.end());
        int i;
        for (i = size - 1; i >= 0; i--) {
            if (citations[i] < size - i) {
                break;
            }
        }
        return size - i - 1;
    }
};
