class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int l = 1;
        int r = row * col - 1;
        int result = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (find(cells, row, col, mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }

private:
    vector<pair<int, int>> d = {{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};

    bool find(vector<vector<int>>&cells, int row, int col, int day) {

        vector<vector<int>>nums(row, vector<int>(col, 0));
        for (int i = 0; i < day; i++) {
            nums[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < col; i++) {
            if (nums[0][i] == 0) {
                q.push({ 0, i });
                nums[0][i] = 1;
            }
        }

        while (q.size()) {
            auto temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            if (x == row - 1) {
                return true;
            }

            for (auto it : d) {
                int nx = x + it.first;
                int ny = y + it.second;
                if (nx >= 0 && ny >= 0 && nx < row
                    && ny < col && nums[nx][ny] == 0) {
                    q.push({ nx, ny });
                    nums[nx][ny] = 1;
                }
            }
        }
        return false;
    }
};
