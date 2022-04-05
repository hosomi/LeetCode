class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {

        int size  = arr.size();
        vector<int> high(size);
        vector<int> low(size);
        map<int, int> map;
        high[size - 1] = low[size - 1] = 1;
        map[arr[size - 1]] = size - 1;
        int result = 1;
        for (int i = size - 2; i >= 0; --i) {
            auto h = map.lower_bound(arr[i]);
            auto l = map.upper_bound(arr[i]);
            if (h != map.end()) {
                high[i] = low[h->second];
            }
            if (l != map.begin()) {
                low[i] = high[(--l)->second];
            }
            if (high[i]) {
                result++;
            }
            map[arr[i]] = i;
        }
        return result;
    }
};
