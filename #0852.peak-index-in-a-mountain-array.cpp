class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return std::max_element(arr.begin(), arr.end()) - arr.begin();
    }
};
