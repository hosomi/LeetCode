class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {

        int x = INT_MAX;
        int y = INT_MAX; 
        for (auto& p : trees) {
            if (p[1] < y || (p[0] < x && p[1] == y)) {
                x = p[0]; 
                y = p[1]; 
            }
        }
        
        map<double, vector<vector<int>>> m; 
        for (auto& p : trees) {
            m[atan2(p[1] - y, p[0] - x)].push_back(p);
        }

        vector<vector<int>> points;
        for (auto& [d, v] : m) {
            std::sort(v.begin(), v.end(), [&](auto& left, auto& right) {
                return std::abs(left[0] - x) + std::abs(left[1] - y)
                    < std::abs(right[0] - x) + std::abs(right[1] - y);
            });
    
            if (d == m.rbegin()->first && points.size()) {
                std::reverse(v.begin(), v.end());
            }
    
            for (auto& x : v) {
                points.push_back(x);
            }
        }
        
        vector<vector<int>> result; 
        for (auto& p : points) {
            while (result.size() >= 2) {
                auto p0 = result.back();
                result.pop_back(); 
                auto p1 = result.back();
                if ((p0[0] - p1[0]) * (
                    p[1] - p0[1]) - (p[0] - p0[0]) * (p0[1] - p1[1]
                    ) >= 0) {
                    result.push_back(p0); 
                    break; 
                }
            }
            result.push_back(p); 
        }
        return result; 
    }
};
