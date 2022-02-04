class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int size = nums.size();
        unordered_map<int, int> m;
        m[0] = -1;
        int result = 0;
        int index = 0;
        for (int i = 0; i < size; i++) {
            index += (nums[i] == 0 ? -1 : 1);
            if (m.find(index) != m.end()) {
                result = std::max(result, i - m[index]);
            } else {
                m[index] = i;
            }
        }
        return result;
    }
};
