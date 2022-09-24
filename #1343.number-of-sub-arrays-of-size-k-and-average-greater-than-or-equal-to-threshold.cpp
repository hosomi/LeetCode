class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int size = arr.size();
        int sum = std::accumulate(arr.begin(), arr.begin() + k, 0);
        int result = 0;
        for (int i = 0, sum = std::accumulate(arr.begin(), arr.begin() + k, 0);
            i + k-1 < size; i++) {

            if (sum >= threshold * k) {
                result++;
            }

            sum += -arr[i];
            if (i + k < size) {
                sum += arr[i + k];
            }
        }
        return result;
    }
};
