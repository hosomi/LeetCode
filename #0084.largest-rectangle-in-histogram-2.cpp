class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int size = heights.size();
        vector<int> left(size);
        vector<int> right(size);
        int index;
        int result = 0;
        for (int i = 0; i < size; i++) {
            index = i - 1;
            while(index >= 0 && heights[index] >= heights[i]) {
                index = left[index];
            }
            left[i] = index;
        }

        for (int i = size-1; i >= 0; i--) {
            index = i + 1;
            
            while (index < size && heights[index] >= heights[i]) {
                index = right[index];
            }
            right[i] = index;
        }
        
        for (int i = 0; i < size; i++) {
            result = std::max(result, (right[i] - left[i] - 1) * heights[i]);
        }

        return result;
    }
};
