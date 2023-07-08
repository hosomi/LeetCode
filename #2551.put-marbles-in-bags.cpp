class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        long long size = weights.size();
        if (k ==1 || k == size) {
            return 0;
        }

        vector<long long> v;
        for(long long i = 0; i < size - 1; i++) {
            v.emplace_back(weights[i] + weights[i + 1]);
        }

        std::sort(v.begin(), v.end());

        long long max = 0;
        long long min = 0;
        for (long long i = 0; i < k - 1; i++) {
            min = min + v[i];
            max = max + v[v.size() - i - 1]; 
        }
        return max-min;
    }
};
