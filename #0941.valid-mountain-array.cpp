class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int size = arr.size();
        if (size < 3) {
            return false;
        }

        int i = 1;
        while (i < size && arr[i] > arr[i-1]){
            i++;
        }
        
        if (i == 1 || i == size) {
            return false;
        }
        
        while (i < size && arr[i] < arr[i-1]) {
            i++;
        }
        return i == size;
    }
};
