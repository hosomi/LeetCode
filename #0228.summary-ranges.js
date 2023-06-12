/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
    
    let left = 0;
    let right = 1;
    let result = [];
    for (let i = 0 ; i < nums.length ; i++ ) {
        if (nums[right]-nums[i] == 1) {
            right++;
            continue;
        }

        result.push(nums[left] === nums[right-1] ? 
            `${nums[left]}` : `${nums[left]}->${nums[right-1]}`);
        left = right;
        right++;
    } 
    return result;
};
