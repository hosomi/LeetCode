class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

        std::sort(tasks.begin(), tasks.end());
        std::sort(workers.begin(),workers.end());

        int n = tasks.size();
        int m = workers.size();
        int low = 0;
        int high = min(n,m);
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isPossible(mid, tasks, workers, pills, strength)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

private:
    bool isPossible(int numTask, vector<int>& tasks, vector<int>& workers, int pills, int strength) {

        multiset<int> ms(workers.end() - numTask, workers.end());

        for (int i = numTask - 1; i >= 0; i--) {
            auto it = ms.end();
            it--;
            if (*it < tasks[i]) {
                if (!pills) {
                    return false;
                }

                it = ms.lower_bound(tasks[i]-strength);
                if (it == ms.end()) {
                    return false;
                }
                pills--;
            }
            ms.erase(it);
        }
        return true;
    }
};
