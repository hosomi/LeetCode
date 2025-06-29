function numSubseq(nums: number[], target: number): number {
    nums.sort((a, b) => a - b);
    
    let res = 0;
    const mod = Math.pow(10, 9) + 7;
    let [left, right] = [0, nums.length - 1];
    const pows: number[] = [1];
    for (let i = 1; i < nums.length; i++) {
        pows.push(pows[i - 1] * 2 % mod);
    }

    while (left <= right) {
        if (nums[left] + nums[right] <= target) res = (res + pows[right - left++]) % mod;
        else right--;
    }
    return res;
};
