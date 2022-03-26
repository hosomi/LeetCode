class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        int size = index.size();
        vector<int> result;
        for (int i = 0; i < size; i++) {
            result.insert(result.begin() + index[i], nums[i]);
        }
        return result;
    }
};
