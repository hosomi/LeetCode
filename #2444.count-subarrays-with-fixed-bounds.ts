function countSubarrays(nums: number[], minK: number, maxK: number): number {
    let lBad = -1;
    let lMin = -1;
    let lMax = -1;
    let count = 0;
    nums.forEach((num, index) => {
        if (num > maxK || num < minK) {
            lBad = index;
        }

        if (num === minK) {
            lMin = index;
        }

        if (num === maxK) {
            lMax = index;
        }

        if (Math.min(lMin, lMax) > lBad) {
            count += (Math.min(lMin, lMax) - lBad);
        }
    });
    return count;
};
