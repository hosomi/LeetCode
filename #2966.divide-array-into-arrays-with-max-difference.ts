function divideArray(nums: number[], k: number): number[][] {
    nums.sort((a, b) => a - b);
    const out = Array.from({length: nums.length / 3}, 
        (_, i) => nums.slice(i * 3, i * 3 + 3));
    return out.some(arr => (arr.at(-1) - arr.at(0)) > k) ? [] : out;
};
