/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function(nums) {
    let arr = [-1, -1];
    let map = {};
    for (let num of nums) {
        if (num in map) {
           arr[0] = num; 
        }
        map[num] = num;
    }
    
    let length = nums.length;
    for (let i = 1; i <= length; i++) {
        if (!(i in map)) {
            arr[1] = i;
            break;
        }
    }
    return arr;
};
