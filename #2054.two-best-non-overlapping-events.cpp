class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        std::sort(events.begin(), events.end(), [](auto& e1, auto& e2) {
            return e1[1] < e2[1];
        });

        map<int, int> m = {{-1, 0}};
        for (auto& e:events) {
            int l = e[0];
            int r = e[1];
            int val = e[2];
            m[r] = std::max(m.rbegin()->second, val);
        }

        int result = 0;
        for (auto& e : events) {
            int l = e[0];
            int r = e[1];
            int val = e[2];
            auto it = prev(m.lower_bound(l));
            result = std::max(result, val + it->second);
        }
        return result;    
    }
};
