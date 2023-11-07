class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

        int size = dist.size();
        vector<double> v(size);
        for (int i = 0; i < size;++i) {
            v[i] = dist[i] / (double)speed[i];
        }

        std::sort(v.begin(), v.end());

        for (int i = 1; i < size; ++i) {
            if (v[i] <= i) {
                return i;
            }
        }
        return size;
    }
};
