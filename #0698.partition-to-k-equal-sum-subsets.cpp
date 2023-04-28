class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        const int sum = reduce(begin(nums), end(nums));
        if (sum % k) {
            return false;
        }

        const int size = std::size(nums);
        const int target = sum / k;
        std::sort(begin(nums), end(nums), greater());
        vector<int> dist(k, 0);
        function<bool(int)> isPossible = [&] (int i) {
            if (i == size) {
                return true;
            }
    
            for (int j = 0; j < k; ++j) {
                if (dist[j] + nums[i] <= target) {
                    dist[j] += nums[i];
                    if (isPossible(i + 1)) {
                        dist[j] -= nums[i];
                        return true;
                    }
    
                    dist[j] -= nums[i];
                }

                if (!dist[j]) {
                    break;
                }
            }
            return false;
        };
        return isPossible(0);
    }
};
