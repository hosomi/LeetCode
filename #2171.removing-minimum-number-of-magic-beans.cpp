class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        std::sort(beans.begin(), beans.end());

        int size = beans.size();
        vector<long long>left(size + 1, 0);
        vector<long long>right(size + 1, 0);
        left[size - 1] = 0;
        right[0] = 0;
        for (int i = 1; i < size; i++) {
            right[i] = right[i - 1] + beans[i - 1];
        }

        for(int i = size - 2; i >= 0; i--) {
            left[i] = left[i + 1] + beans[i + 1];
        }

        long long result = 1e16;
        for (int i = 0; i < size; i++) {
            result = std::min(result, 
                right[i] + (left[i] - (size - i - 1) * 1ll * beans[i]));
        }
        return result;
    }
};
