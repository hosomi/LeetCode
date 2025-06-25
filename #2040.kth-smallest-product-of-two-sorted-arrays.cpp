class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) {
            swap(n1, n2);
            nums1.swap(nums2);
        }

        long long l = -1e10;
        long long r = 1e10;
        while (l < r) {
            long long mid = floor((l + r) / 2.);
            long long cnt = 0;
            for (auto &num : nums1) {
                if (num == 0) {
                    if (mid >= 0) {
                        cnt += n2;
                    }
                } else if (num > 0) {
                    double target = (double)mid / num;
                    int j = upper_bound(begin(nums2), end(nums2), target) - begin(nums2);
                    cnt += j;
                } else {
                    double target = (double)mid / num;
                    int j = lower_bound(begin(nums2), end(nums2), target) - begin(nums2);
                    cnt += (n2 - j);
                }
            }

            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
