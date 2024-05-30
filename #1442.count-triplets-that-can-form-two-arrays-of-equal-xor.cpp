class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int result = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = i; j < n; j++) {
                x = x ^ arr[j];
                int y = 0;
                for (int k = j + 1; k < n; k++) {
                    y = y ^ arr[k];
                    if (y == x) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
