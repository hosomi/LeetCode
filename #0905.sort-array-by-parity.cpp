class Solution {
    public:
        vector<int> sortArrayByParity(vector<int>& A) {

            stable_sort(begin(A), end(A), [](int a, int b) {
                return a % 2 < b % 2;
            });
            return A;
        }
};
