class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int h;
        int result = 0;
        while (left < right) {
            h = min(height[left], height[right]);
            result = max(result, h * (right - left));

            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};
