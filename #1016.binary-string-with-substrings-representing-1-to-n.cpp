class Solution {
public:
    bool queryString(string s, int n) {

        unordered_set<int> us;
        int size = s.size();
        for (int i = size - 1; i >= 0; i--) {
            int num = 0;
            int min = std::min(size - i, 31);
            for (int j = 1; j <= min; j++) {
                num = num * 2 + (s[i + j - 1] == '1' ? 1 : 0);
                if (0 < num && num <= n) {
                    us.insert(num);
                }
            }
            
            if (us.size() == n) {
                return true;
            }
        }
        return false;
    }
};
