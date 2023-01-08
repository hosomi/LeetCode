class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        int v[10000]{0};
        for (const auto & i : deadends) {
            v[stoi(i)] = 1;
        }

        int out{INT_MAX};
        for (queue<pair<int, int>> q({{stoi(target), 0}}); !empty(q); ) {
            auto [code, steps] = q.front();
            q.pop();
            if (!v[code]) {
                if (!code) {
                    return steps;
                }
    
                for (auto p{1}, c{code}; p < 10000; p *= 10, c /= 10) {
                    q.emplace(c % 10 != 9 ? code + p : code - 9 * p, steps + 1);
                    q.emplace(c % 10 != 0 ? code - p : code + 9 * p, steps + 1);
                }
                v[code] = 1;
            }
        }
        return -1;
    }
};
