class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        int size = arr.size();
        int counter = 0;
        int result = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > result) {
                result = arr[i];
                counter = 0;
            }

            if (++counter == k) {
                break;
            }
        }
        return result;
    }
};
