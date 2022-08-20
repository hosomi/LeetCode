class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        if (startFuel > target) {
            return 0;
        }

        int size = stations.size();
        vector<long long int> v(size + 1 ,0);
		v[0] = startFuel;
        std::sort(stations.begin(), stations.end(), isSort);
        for (int i = 0; i < size; i++) {
            for (int j = i; j >= 0; j--) {
                if (v[j] >= stations[i][0]) {
                    v[j + 1] = std::max(v[j + 1], v[j] + stations[i][1]);
                } else {
                    break;
                }
            }
        }

        for (int i = 0; i <= size; i++) {
            if (v[i] >= target) {
                return i;
            }
        }
        return -1;
    }

private:
    static bool isSort(const vector<int> &x,const vector<int> &y) {
        return x[0] < y[0];
    }
};
