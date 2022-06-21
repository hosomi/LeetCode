class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        int size = heights.size();
        priority_queue<int> pq;
        int i = 1;
        for (; i < size; i++) {
            int d = heights[i] - heights[i - 1];
            if (d <= 0) {
                continue;
            } else if (d <= bricks) {
                bricks -= d;
                pq.push(d);
            } else if (!pq.empty() && ladders && pq.top() > d) {
                bricks += pq.top() - d;
                pq.pop();
                --ladders;
                pq.push(d);
            } else if (ladders) {
                --ladders;
            } else {
                break;
            }
        }
        return i - 1;
    }
};
