/**
 * @param {number[]} nums
 * @return {number}
 */
var longestArithSeqLength = function(nums) {

    let length = nums.length;
    let result = 1;
    for (let i = 0; i < length; i++) {
        for (let j = i + 1; j < length; j++) {
            let currDiff = nums[j] - nums[i];
            let next = nums[j] + currDiff;
            let count = 1;
            for (let k = j + 1; k < length; k++) {
                if (next === nums[k]) {
                    next = nums[k] + currDiff;
                    count++;
                }
            }
            result = Math.max(result, count + 1);
        }
    }
    return result;
};
