class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {

        int size = arr.size();
        std::sort(arr.begin(), arr.end());
        map<int,long> m;
        int mod = std::pow(10, 9) + 7;
        int result = 0;
        for (int i = 0; i < size; i++) {
            m[arr[i]]=1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j]==0) {
                    m[arr[i]] = (m[arr[i]] + m[arr[j]] * m[arr[i] / arr[j]]) % mod;
                }
            }
            result = (result + m[arr[i]]) % mod;
        }
        return result;
    }
};
