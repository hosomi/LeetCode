class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int size = arr.size();
        for (int i = size - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                arr.insert(arr.begin() + i, 0);
            }
        }
        arr.resize(size);
    }
};
