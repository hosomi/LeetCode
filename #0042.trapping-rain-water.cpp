class Solution {
public:
    int trap(vector<int>& height) {

        int size = height.size();
        auto itHead = cbegin(height);
        int h;
        auto itNext = cend(height);
        int n;

        int result = 0;
        for (int i = 0; i < size; ++i) {
            h = *max_element(itHead, itHead + i + 1);
            n = *max_element(itHead + i, itNext);
            result += min(h, n) - height[i];
        }

        return result;
    }
};
