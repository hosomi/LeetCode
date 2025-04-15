class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {

        const int n = nums1.size();
        vector<int> indexes(n, 0);
        for (int i = 0; i < n; ++i) {
            indexes[nums1[i]] = i;
        }
        
        vector<int> nums3(n);
        for (int i = 0; i < n; ++i) {
            nums3[i] = indexes[nums2[i]];
        }

        vector<int> smaller(n, 0);
        std::iota(indexes.begin(), indexes.end(), 0);
        mergeSort(smaller, nums3, indexes.begin(), indexes.end());

        long long result = 0;
        for (int i = 1; i < n - 1; ++i) {
            long long left = smaller[i];
            long long right = n - nums3[i] - 1 - i + left;
            result += left * right;
        }
        return result;
    }

private:
    void mergeSort(vector<int> &result, vector<int> &nums, vector<int>::iterator begin,vector<int>::iterator end) {

        if (end - begin <= 1) {
            return;
        }
        
        auto mid = begin + (end - begin) / 2;
        mergeSort(result, nums, begin, mid);
        mergeSort(result, nums, mid, end);
        for (auto i = begin, j = mid; j != end; ++j) {
            while (i != mid && nums[*i] < nums[*j]) {
                ++i;
            }
            result[*j] += i - begin;
        }

        std::inplace_merge(begin, mid, end, [&](auto i, auto j) {
            return nums[i] < nums[j];
        });
    }
};
