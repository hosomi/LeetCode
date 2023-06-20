/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var getAverages = function(nums, k) {
    
    let rad = k * 2 + 1;
    let arr = Array(nums.length).fill(-1);
    let start = 0;
    let sum = 0;
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        if(i >= rad - 1) {
            arr[Math.floor((i + start) / 2)] =  Math.floor(sum / rad);
            sum -= nums[start];
            start++;
        }
    }
    return arr;
};
