class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        depthFirstSearch(candidates, target, 0, result, v);
        return result;
    }

private:
    void depthFirstSearch(const vector<int>& candidates,
                          int target, int start,
                          vector<vector<int>>& result,
                          vector<int>& v) {

        if (target == 0) {
            result.push_back(v);
            return;
        }

        int candidate;
        for (int i = start; i < candidates.size(); ++i) {
            candidate = candidates[i];
            if (candidate > target) {
                return;
            }

            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            v.push_back(candidate);
            depthFirstSearch(candidates, target - candidate, i + 1, result, v);
            v.pop_back();
        }
    }
};
