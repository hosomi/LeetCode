function findLHS(nums: number[]): number {
    const numCount = new Map<number, number>();
    let maxLen = 0;
    for (const num of nums) {
        numCount.set(num, (numCount.get(num) || 0) + 1);
    }

    for (const num of numCount.keys()) {
        if (numCount.has(num + 1)) {
            maxLen = Math.max(maxLen, numCount.get(num)!
                + numCount.get(num + 1)!);
        }
    }

    return maxLen;
};
