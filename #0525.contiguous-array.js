/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function(nums) {
    let count = 0;
    let max = 0;
    let hash = { 0:-1 };
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 0) {
            count--;
        } else {
            count++;
        }

        if (hash[count] != null) {
            max = Math.max(max, i - hash[count]);
        } else {
            hash[count] = i;
        }
    }  
    return max;
};
