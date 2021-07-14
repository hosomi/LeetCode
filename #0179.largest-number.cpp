class Solution {
public:
    string largestNumber(vector<int>& nums) {

        int me = *std::max_element(nums.begin(), nums.end());
        if (me == 0) {
            return "0";
        }

        std::sort(nums.rbegin(), nums.rend(), [](int& a, int& b) {
            return std::to_string(a)
                + std::to_string(b) < std::to_string(b) + std::to_string(a);
        });

        string result;
        for (int& num : nums) {
            result += std::to_string(num);
        }
        return result;
    }
};
