class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {

        int size = s.size();
        int left = 0;
        int right = 0;
        vector<vector<int>> result;
        while (left < size) {
            while (s[left] == s[right]) {
                right++;
            }
            if (right - left >= 3) {
                result.push_back({left, right-1});
            }
            left = right;
        }
        return result;
    }
};
