class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {

        vector<vector<int>> events(rectangles.size() * 2);
        int i = 0;
        for (vector<int>& rec : rectangles) {
            events[i++] = {rec[1], 0, rec[0], rec[2]};
            events[i++] = {rec[3], 1, rec[0], rec[2]};
        }

        std::sort(events.begin(), events.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[0] < b[0];
            }
        );
        
        vector<vector<int>> actives;
        int y1 = events[0][0];
        long result = 0;
        for (vector<int>& event : events) {
            int y2 = event[0];
            bool isClose = event[1];
            int x1 = event[2], x2 = event[3];
            long query = 0;
            int index = INT_MIN;
            for(vector<int>& active : actives){
                index = std::max(index, active[0]);
                query += std::max(active[1] - index, 0);
                index = std::max(index, active[1]);
            }
            
            result += query * (y2 - y1);
            if (!isClose){
                actives.push_back({x1, x2});
                std::sort(actives.begin(), actives.end(),
                    [](vector<int>& a, vector<int>& b) {
                        return a[0] < b[0];
                    });
            } else {
                for (auto it = actives.begin(); it != actives.end(); it++) {
                    if ((*it)[0] == x1 && (*it)[1] == x2) {
                        actives.erase(it);
                        break;
                    }
                }
            }
            y1 = y2;
        }
        result %= (int)1e9+7;
        return result;
    }
};
