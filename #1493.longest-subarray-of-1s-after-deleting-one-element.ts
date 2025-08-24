function longestSubarray(nums: number[]): number {
    var max = 0;
    var strs = nums.join('').replaceAll(/0{2,}/g, '.').split('.');
    for (let str of strs) {
        if (!str) {
            continue;
        }
        
        const arr = str.split('0');
        if (arr.length === 1) {
            max = Math.max(arr[0].length, max);
        } else {
            for (let i = 0; i < arr.length - 1; i++) {
                max = Math.max(arr[i].length + arr[i+1].length, max);
            }
        }
    }
    return nums.includes(0) ? max : --max;
};
