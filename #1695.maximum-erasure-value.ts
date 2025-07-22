function maximumUniqueSubarray(nums: number[]): number {
    const set = new Set<number>();
    let maxSum = -Infinity;
    let sum = 0;
    for (let l = 0, r = 0; r < nums.length; r++) {
        while (set.has(nums[r])) {
            set.delete(nums[l]);
            sum -= nums[l];
            l++;
        }
        set.add(nums[r]);
        sum += nums[r]
        maxSum = Math.max(sum, maxSum);
    }
    return maxSum;
};
