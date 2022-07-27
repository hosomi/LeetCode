class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int size = arr.size();
        vector<int> result(size);
        for (int i = 0; i < size; i++) {
            int max = 0;
            for (int j = 1; j <= k && i - (j - 1) >= 0; j++) {
                max = std::max(max, arr[i-(j-1)]);
                result[i] = std::max(result[i],
                     ((i-j >= 0) ? result[i-j] : 0) + max * j);
            }
            cout << result[i] << endl;
        }
        return result[size - 1];
    }
};
