class Solution {
public:
    int maxUniqueSplit(string s) {

        unordered_map<string_view, int> m;
        int ret = 0;
        int k = 0;

        function<void(string_view)> solve = [&] (string_view s) {
            if (s.empty()) {
                return;
            }

            const int n = size(s);
            for (int i = 1; i <= n; ++i) {
                auto left = s.substr(0, i);
                auto right = s.substr(i);
                if (++m[left] == 1) {
                    ret = max(ret, ++k);
                }

                solve(right);
                
                if (--m[left] == 0) {
                    --k;
                }
            }
        };

        solve(s);
        return ret;
    }
};
