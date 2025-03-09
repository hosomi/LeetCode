class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n = colors.size();
        int missMatch = 0;
        int ans = 0;
        for (int i = 0; i < n + k - 1; i++) {
            if (colors[i % n] != colors[(i + 1) % n]) {
                missMatch++;
            } else {
                missMatch = 1;
            }

            if (missMatch >= k) {
                ans++;
            }
        }
        return ans;
    }
};
