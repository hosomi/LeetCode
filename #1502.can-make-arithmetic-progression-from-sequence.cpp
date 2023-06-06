class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int size = arr.size();
        if (size <= 2) {
            return true;
        }
        
        std::sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];
        for (int i = 1; i + 1 < size; ++i) {
            if (arr[i+1] - arr[i] != diff) {
                return false;
            }
        }
        return true;
    }
};
