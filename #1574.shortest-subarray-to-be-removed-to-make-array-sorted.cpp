class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int j(size(arr) - 1);
        for (; j && arr[j - 1] <= arr[j]; --j);

        int out(j);
        for (int i{}; i < size(arr) && (!i || arr[i - 1] <= arr[i]);) {
            j < size(arr)
            && arr[j] < arr[i]
            || j <= i ? ++j : out = std::min(out, j - (++i));
        }
        return out;
    }
};
