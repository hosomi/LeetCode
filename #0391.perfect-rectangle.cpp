class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int area = 0;
        int bot_x = INT_MAX;
        int bot_y = INT_MAX;
        int top_x = INT_MIN;
        int top_y = INT_MIN;

        unordered_map<int, unordered_map<int, int>> um;

        for (auto& rec : rectangles) {
            int x1 = rec[0];
            int y1 = rec[1];
            int x2 = rec[2];
            int y2 = rec[3];

            area += (y2 - y1) * (x2 - x1);

            um[x1][y1]++;
            um[x2][y2]++;
            um[x1][y2]++;
            um[x2][y1]++;
 
            bot_x = min(bot_x, x1);
            bot_y = min(bot_y, y1);
            top_x = max(top_x, x2);
            top_y = max(top_y, y2);
        }

        if ((top_x - bot_x) * (top_y - bot_y) != area) { 
            return false;
        }

        for (auto& i : um) {
            for (auto& j : i.second) {
                if ((i.first == bot_x || i.first == top_x) && (j.first == bot_y || j.first == top_y) && j.second != 1) {
                    return false;
                }

                if (j.second & 1) {
                    if ((i.first == bot_x || i.first == top_x) && (j.first == bot_y || j.first == top_y)) {
                        continue;
                    }
                    return false;
                }
            }
        }

        return true;
    }
};
