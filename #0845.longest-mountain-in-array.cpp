class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int size = arr.size();
        if (size < 3) {
            return 0;
        }

        int result = 0;
        int left = 0;
        int right = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[i - 1]) {
                if (right) {
                    left = 0;
                    right = 0;
                }
                left += (1 + (left == 0));
            } else if (arr[i] < arr[i-1] && left) {
                right += 1;
            } else {
                left = 0;
                right = 0;
            }
            result = std::max((left + right) * (left && right), result);
        }
        return result;
    }
};
