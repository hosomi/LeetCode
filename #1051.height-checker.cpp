class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int size = heights.size();
        vector<int> v = heights;
        std::sort(v.begin(), v.end());
        int num = 0;
        for (int i = 0; i < size; i++) {
            if (heights[i] != v[i]) {
                num++;
            }
        }
        return num;
    }
};
