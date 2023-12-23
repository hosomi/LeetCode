class Solution {
public:
    bool isPathCrossing(string path) {
        
        int x = 0;
        int y = 0;
        set<pair<int, int>> s;
        s.insert(pair<int, int>(0, 0));
        for (auto& p : path) {
            if (p == 'N') {
                y++;
            } else if(p == 'S') {
                y--;
            } else if(p == 'E') {
                x++;
            } else {
                x--;
            }

            pair<int, int> temp = pair<int, int>(x, y);
            if (s.count(temp)) {
                return true;
            }

            s.insert(temp);
        }
        return false;
    }
};
