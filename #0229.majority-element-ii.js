/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    let dict = {};
    for (let i = 0; i < nums.length; i++ ) {
        if (!dict[nums[i]]) {
            dict[nums[i]] = 1;
        } else {
            dict[nums[i]]++;
        }
    }

    let floor = Math.floor(nums.length / 3);
    let results = [];
    for (let [key,val] of Object.entries(dict)) {
        if (val > floor) {
            results.push(key);
        }
    }
    return results;
};
