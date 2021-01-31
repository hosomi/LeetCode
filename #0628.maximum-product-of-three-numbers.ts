function maximumProduct(nums: number[]): number {

    const length: number = nums.length;
    if (length < 3) {
        return 0;
    }
    nums.sort((n1, n2) => (n1 < n2 ? -1 : 1));
    return Math.max(nums[0] * nums[1] * nums[length - 1], nums[length -3] * nums[length -2] * nums[length -1]);
};
