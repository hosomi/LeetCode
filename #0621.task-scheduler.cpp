class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> v(26, 0);
        int max = 0;
        for (char task : tasks) {
            v[task-'A']++;
            max = std::max(max, v[task-'A']);
        }

        int count = 0;
        for (int i:v) {
            count += (i == max);
        }

        int total = (n + 1) * (max - 1) + 1 + (count - 1);
        return std::max(total, (int)tasks.size());   
    }
};
