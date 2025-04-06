function largestDivisibleSubset(nums: number[]): number[] {
    nums.sort((a, b) => a - b);
    let max = [];
    const cache = []
    for (let i=nums.length - 1; i>=0; i -= 1) {
        let bestMatch = [];
        for (let j=i + 1; j < nums.length; j += 1) {
            if ((nums[i] % nums[j] === 0 || nums[j] % nums[i] === 0) 
                && cache[j].length >= bestMatch.length) {
                bestMatch = cache[j];
            }
        }
        cache[i] = bestMatch.concat(nums[i]);
        if (cache[i].length > max.length) {
            max = cache[i];
        }
    }
    return max;
};
