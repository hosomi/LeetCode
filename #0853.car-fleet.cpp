class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int size = position.size();
        vector<pair<int, double>> v(size);
        for (int i = 0; i < size; i++) {
            v[i] = std::make_pair(position[i], (double)(target - position[i]) / speed[i]);
        }
        
        std::sort(v.begin(), v.end());
        
        int result = size;
        for (int i = size - 2; i >= 0; i--) {
            if (v[i].second <= v[i+1].second) {
                result--;
                v[i].second = v[i+1].second;
            }
        }
        return result;
    }
};
