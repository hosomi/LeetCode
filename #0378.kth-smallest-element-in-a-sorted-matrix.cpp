class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {

            int size = matrix.size();
            int low = matrix[0][0];
            int high = matrix[size -1][size - 1];

            while (low < high) {
                int mid = (low + high) / 2;
                int index = 0;
                int j;

                for (int i = 0; i < size; i++) {
                    j = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                    index += j;
                }

                if (index < k) {
                    low = mid +1;
                } else if (index >= k)  {
                    high = mid;
                }
            }
            return low;
    }
};
