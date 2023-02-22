class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int result = 0;
        while (arr.size() > 1) {
            auto a = min_element(arr.begin(), arr.end());
            int min = a - arr.begin();
            result += std::min(min >= 1 ?
                arr[min-1]: INT_MAX, min + 1 < arr.size() ? 
                arr[min+1] : INT_MAX) * (*a);
            arr.erase(arr.begin() + min);
        }
        return result;
    }
};
