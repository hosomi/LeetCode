class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int size = nums.size();
        long long result = 0;
        for (int i = 0; i < size;) {
            while (i < size && (nums[i] < minK || nums[i] > maxK)) {
                i++;
            }

            if (i == size) {
                break;
            }

            int l = i;
            while (i < size && (nums[i] >= minK && nums[i] <= maxK)) {
                i++;
            }

            int last_min = l - 1;
            int last_max = l - 1;
            long long invalid = 0;
            long long len = i - l;
            while (l < i) {
                if (nums[l] == minK) {
                    last_min = l;
                }

                if (nums[l] == maxK) {
                    last_max = l;
                }

                invalid += l - std::min(last_max, last_min);
                l++;
            }

            result += (len * (len + 1)) / 2 - invalid;
        }

        return result;
    }
};
