class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int size = nums.size();
        if (size < 3) {
            return false;
        }

        int max = INT_MIN;
        stack<int> st;
        st.push(nums[size - 1]);
        for (int i = size - 1; i >= 0; --i) {
            if (nums[i] < max) {
                return true;
            }
            while (!st.empty() && nums[i] > st.top()) {
                max = std::max(max, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
