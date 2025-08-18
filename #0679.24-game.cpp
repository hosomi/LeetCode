class Solution {
public:
    bool judgePoint24(vector<int>& cards) {

        sort(cards.begin(),cards.end());

        int n = size(cards);
        double eps = 1e-6;
        auto shuffled = cards;
        unordered_set<string> used;
        do {
            auto values = getValues(cards, 0, n-1);
            for (auto v: values) {
                if (abs(v-24) < eps) {
                    return true;
                }
            }
        } while (next_permutation(cards.begin(), cards.end()));
        return false;
    }

private:
      vector<double> getValues(vector<int>& nums, int nums_s, int nums_e) {

        if (nums_s == nums_e) {
            return {double(nums[nums_s])};
        }

        vector<double> result;
        for (int i= nums_s; i< nums_e;i++) {
            vector<double> leftValues = getValues(nums,nums_s, i);
            vector<double> rightValues = getValues(nums,i+1, nums_e);
            for (double v1: leftValues) {
                for (double v2: rightValues) {
                    result.push_back(v1 * v2);
                    if (v2 != 0) {
                        result.push_back(v1 / v2);
                    }
                    result.push_back(v1 + v2);
                    result.push_back(v1 - v2);
                }
            }
        }
        return result;
      }
};
