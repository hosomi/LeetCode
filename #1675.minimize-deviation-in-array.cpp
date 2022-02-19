class Solution {
public:
    int minimumDeviation(vector<int>& nums) {

        int size = nums.size();
        priority_queue<int>pq;
        int min = 2e9;
        for (int i = 0; i < size; i++) {
            if (nums[i] % 2 == 1) {
                nums[i] *= 2;
            }
            min = std::min(min, nums[i]);
            pq.push(nums[i]);
        }

        while (pq.top() % 2 == 0 && pq.top() / 2 >= min) {
            int x = pq.top();
            pq.pop();
            while (x % 2 == 0 && x / 2 >= min) {
                x /= 2;
            }
            pq.push(x);
        }

        int result = pq.top() - min;
        while (pq.top() % 2 == 0) {
            int x = pq.top();
            pq.pop();
            x /= 2;
            min = std::min(min, x);
            pq.push(x);
            result = std::min(result, pq.top() - min);
        }
        return result;
    }
};
