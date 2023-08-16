/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    let q = [];
    let result = [];
    for (let i = 0; i < nums.length; i++) {
        while (q.length && nums[i] >= q.at(-1).num) {
            q.pop();
        }

        q.push({idx: i, num: nums[i]});
        if (i >= k - 1) {
            while (q[0].idx <= i - k) {
                q.shift();
            }
            result.push(q[0].num);
        }
    }
    return result;
};
