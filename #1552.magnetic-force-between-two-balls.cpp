class Solution {
public:
    int maxDistance(vector<int>& position, int m) {

        std::sort(position.begin(), position.end());

        int n = position.size();
        int low = 1;
        int high = position[n - 1] - position[0];
        int result = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            int cntcow = 1;
            int lastcow = position[0];
            for (int i = 1; i <n; i++) {
                if ((position[i]-lastcow) >= mid) {
                    cntcow++;
                    lastcow = position[i];
                }
            }

            if (cntcow >= m) { result=mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};
