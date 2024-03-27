/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
   let count = 0;
   for (let i = 0; i < nums.length; i++) {
        let num = nums[i];
        let j = i + 1;
        while (num < k) {
            count++;
            num *= nums[j];
            j++;
        }  
    }
    return count;
};
