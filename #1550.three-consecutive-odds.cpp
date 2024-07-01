class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int odd = 0;
        for (auto i = 0; i < arr.size() && odd < 3; ++i) {
            odd = arr[i] % 2 ? odd + 1 : 0;
        }
        return odd == 3;
    }
};
