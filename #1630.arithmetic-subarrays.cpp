class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int size = l.size();
        vector<bool> results;
        for (int i = 0;i < size; i++) {
            bool chk = 1;
            vector<int> v(begin(nums) + l[i], begin(nums) + r[i] + 1);
            std::sort(v.begin(), v.end());
            int size2 = v.size();
            for (int j = 1; j < size2 - 1; j++) {
                if (v[j] - v[j - 1] != v[j + 1] - v[j]) {
                    chk = 0;
                }
            }
            results.push_back(chk);
        }
        return results;
    }
};
