/**
 * @param {number[]} nums
 * @param {number} n
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeSum = function(nums, n, left, right) {
    const minqueue = new MinPriorityQueue({priority : x=> x[0]});
    for (let i = 0; i < n; i++) {
        minqueue.enqueue([nums[i], i]);
    }

    let mod = Math.pow(10, 9) + 7;
    let result = 0;
    for (let i = 1; i <= right; i++) {
        let [sum,index] = minqueue.dequeue().element;
        if (i >= left) {
            result = (result + sum) % mod;
        }
        if (index < n - 1) {
            minqueue.enqueue([sum + nums[index + 1],index + 1]);
        }
    }
    return result;
};
