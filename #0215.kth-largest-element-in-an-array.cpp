class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> result;
        for (int num : nums) {
            result.push(num);
            if (result.size() > k) {
                result.pop();
            }
        }
        return result.top();
    }
};
