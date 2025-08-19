function zeroFilledSubarray(nums: number[]): number {
    let j = -1;
    let zeroes = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i]) {
            j = i;
        } else {
            zeroes += i - j;
        }
    }
    return zeroes;
};
