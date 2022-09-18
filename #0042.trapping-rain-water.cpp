class Solution {
public:
    int trap(vector<int>& height) {

        int size = height.size();
        if (size == 0) {
            return 0;
        }

        int i;
        int left[size];
        int right[size];
        left[0] = height[0];
        for(i = 1; i < size; i++) {
            left[i] = std::max(left[i - 1], height[i]);
        }
        
        for(i = size - 2; i >= 0; i--) {
            right[i] = std::max(right[i + 1], height[i]);
        }

        int result = 0;
        for (i = 1; i <= size-2; i++) {
            result += (std::min(left[i], right[i]) - height[i]);
        }
        return result;
    }
};
