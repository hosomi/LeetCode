class Solution {
public:
    int hIndex(vector<int>& citations) {

        int size = citations.size();
        int left = 0;
        int right = size - 1;
        int index;
        int citation;
        while (left <= right) {
            index = (left + right) / 2;
            citation = size - index;
            if (citations[index] < citation) {
                left = index + 1;
            } else {
                right = index - 1;
            }
        }
        return size - left;
    }
};
