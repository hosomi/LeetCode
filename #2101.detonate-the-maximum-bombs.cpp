class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        int size = bombs.size();
        auto bfs = [&](int& i) {
            vector<bool> visits(size, false);
            int detonated = 0;
            queue<int> q;
            q.push(i);
            visits[i] = true;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                detonated += 1;

                for (int j = 0; j < size; j++) {
                    if (!visits[j]) {
                        long long b0 = (long long)(bombs[j][0] - bombs[curr][0]) * (long long)(bombs[j][0] - bombs[curr][0]);
                        long long b1 = (long long)(bombs[j][1] - bombs[curr][1]) * (long long)(bombs[j][1] - bombs[curr][1]);
                        long long b2 = (long long)bombs[curr][2] * (long long)bombs[curr][2];
                        if (b0 + b1 <= b2) {
                            q.push(j);
                            visits[j] = true;
                        }
                    }
                }
            }
            return detonated;
        };
        
        int result = 0;
        for(int i = 0; i < size; i++){
            result = std::max(result, bfs(i));
        }
        return result;
    }
};
