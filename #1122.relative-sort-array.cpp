class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        std::sort(arr1.begin(), arr1.end(), [&](int left, int right) {
            auto aleft = find(arr2.begin(), arr2.end(), left);
            auto aright = find(arr2.begin(), arr2.end(), right);
            return aleft == aright ? left < right : aleft < aright;
        });
        return arr1;
    }
};
