class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> cursor;
        std::sort(candidates.begin(), candidates.end());
        depthFirstSearch(candidates, target, 0, cursor, result);
        return result;
    }

private:
    void depthFirstSearch(vector<int>& candidates, int target, int start,
                          vector<int>& cursor, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(cursor);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break;
            }
            cursor.push_back(candidates[i]);
            depthFirstSearch(candidates, target - candidates[i], i, cursor, result);
            cursor.pop_back();
        }
    }
};
