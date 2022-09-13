class Solution {
public:
    Solution(vector<vector<int>>& rects) {

        this->rects = rects;
        this->area = 0;
        int size = rects.size();
        for (int i = 0; i < size; ++i) {
            int x1 = rects[i][0];
            int y1 = rects[i][1];
            int x2 = rects[i][2];
            int y2 = rects[i][3];
            this->area += (x2-x1+1) * (y2-y1+1);
            this->index[this->area] = i;
        }
    }
    
    vector<int> pick() {

        int ri = rand() % this->area + 1;
        auto rit = this->index.lower_bound(ri);
        int ridx = rit->second;

        vector<int> rect = rects[ridx];
        int x1 = rect[0];
        int y1 = rect[1];
        int x2 = rect[2];
        int y2 = rect[3];
        ri = rit->first - ri;
        int x = x1 + ri % (x2-x1+1);
        int y = y1 + ri / (x2-x1+1);
        return {x, y};
    }

private:
    vector<vector<int>> rects;
    map<int, int> index;
    int area;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
