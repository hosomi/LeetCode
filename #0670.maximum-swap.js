/**
 * @param {number} num
 * @return {number}
 */
var maximumSwap = function(num) {
    const nums = [...num.toString()].map(Number);
    let max = nums.length - 1;
    const maxSwap = (new Array(nums.length)).fill(0);

    for (let i = nums.length - 1; i >= 0; i--) {
        if (nums[i] > nums[max]) {
            max = i;
        }
        maxSwap[i] = nums[i] === nums[max] ? i : max;
    }

    for (let i = 0; i < maxSwap.length; i++) {
        if (maxSwap[i] !== i) {
            [nums[i], nums[maxSwap[i]]] = [nums[maxSwap[i]], nums[i]];
            return Number(nums.join(''));
        }
    }
    return num;
};
