class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        std::sort(arr.begin(), arr.end(), [x](const int& y, const int& z) {
            return abs(y - x) == abs(z - x) ? y < z : abs(y - x) < abs(z - x);
        });
        
        vector<int> result(arr.begin(), arr.begin() + k);
        std::sort(result.begin(), result.end());
        
        return result;
    }
};
