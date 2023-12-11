class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
    
        int size = arr.size();
        for (int i = 0; i < size; i++) {
            if (arr[i] == arr[i + size / 4]) {
                return arr[i];
            }
        }
        return arr[size - 1];
    }
};
