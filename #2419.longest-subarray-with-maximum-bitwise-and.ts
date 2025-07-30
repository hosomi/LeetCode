function longestSubarray(nums: number[]): number {
    let max = 0;
    let count = 0;
    let maxCount = 0;
    for (const num of nums) {
        if (num > max) {
            max = num;
            count = 0;
            maxCount = 0;
        }
        count = num === max ? count + 1 : 0;
        maxCount = Math.max(maxCount, count);
    }
    return maxCount;
};
