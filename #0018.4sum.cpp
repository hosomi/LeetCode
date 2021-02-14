class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        if (target > 0 && target > 4 * nums.back()) {
            return {};
        }

        if (target < 0 && target < 4 * nums.front()) {
            return {};
        }

        int size = nums.size();
        unordered_map<int, int> index;
        for (int i = 0; i < size; ++i) {
          index[nums[i]] = i;
        }

        set<vector<int>> v;    
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                for (int k = j + 1; k < size; k++) {
                    int t = target - nums[i] - nums[j] - nums[k];
                    if (t < nums[k]) {
                        break;
                    }
                    auto it = index.find(t);
                    if (it == index.end() || it->second <= k) {
                        continue;
                    }
                    v.insert({nums[i], nums[j], nums[k], t});
                }
          }
        }

        return vector<vector<int>>(begin(v), end(v));
    }
};
