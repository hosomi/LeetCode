class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        std::sort(arr.begin(), arr.end());

        if (arr[0] != 1) {
            arr[0] = 1;
        }

        int size = arr.size();
        for (int i = 1; i < size; i++) {
            if (arr[i] - arr[i-1] > 1) {
                arr[i] = arr[i-1] + 1;
            }
        }
        return arr[size - 1];
    }
};
