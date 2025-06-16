function maximumDifference(nums: number[]): number {
    let min = Infinity;
    return nums.reduce((acc, t) => {
        if (t - min > acc && t - min !== 0) {
            acc = t - min;
        }

        if (min > t) {
            min = t;
        }
        
        return acc;
    }, -1);
};
