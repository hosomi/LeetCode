class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        int size = requests.size();
        int result = 0;
        for (int i = 0; i < (1 << size); ++i) {
            vector<int> out(n);
            vector<int> in(n);
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) {
                    ++out[requests[j][0]];
                    ++in[requests[j][1]];
                }
            }
            
            if (in == out) {
                result = std::max(result,
                    accumulate(out.begin(), out.end(), 0));
            }
        }
        return result;
    }
};
