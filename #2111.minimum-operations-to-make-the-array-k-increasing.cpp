class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {

        int size = arr.size();
        int result = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> v{arr[i]};
            int len = 1;
            for (int j = i + k; j < size; j += k) {
                auto i = std::upper_bound(begin(v), end(v), arr[j]);
                if (i == end(v)) v.push_back(arr[j]);
                else *i = arr[j];
                ++len;
            }
            result += len - v.size();
        }
        return result;
    }
};
