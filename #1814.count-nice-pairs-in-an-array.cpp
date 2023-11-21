class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        static const int MOD = 1e9 + 7;
        unordered_map<int, int> m;
        int result = 0;
        for (const auto& i : nums) {
            result = (result + m[i - countNicePairs(i)]++) % (MOD);
        }
        return result;
    }

private:
    int countNicePairs(int i) {

        int result = 0;
        for (; i; i /= 10) {
            result = result * 10 + i % 10;
        }
        return result;
    }
};
