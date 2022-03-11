class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<bool> visited(nums.size());
        int result = 0;
        numSquarefulPerms(nums, visited, result, cur);
        return result;
    }

private:

    int squareful(int x, int y) {

        int s = sqrt(x + y);
        return s * s == x + y;
    }

    void numSquarefulPerms(vector<int>& nums, vector<bool>& visited, int& result, vector<int>& cur) {

        if (cur.size() == nums.size()) {
            ++result;
            return;
        }

        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (visited[i]) {
                continue;
            }

            if (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1]) {
                continue;
            }

            if (!cur.empty() && !squareful(cur.back(), nums[i])) {
                continue;
            }

            cur.push_back(nums[i]);
            visited[i] = true;
            numSquarefulPerms(nums, visited, result, cur);
            visited[i] = false;
            cur.pop_back();
        }
    }
};
