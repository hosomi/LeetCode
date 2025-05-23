/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number[][]} edges
 * @return {number}
 */
var maximumValueSum = function(nums, k, edges) {
    const n = nums.length;
    const temp = Array.from({ length: n }, () => [-1, -1]);
    function calculateMax(curInd, isEven) {
        if (curInd === n) {
            return isEven === 1 ? 0 : -Infinity;
        }
        if (temp[curInd][isEven] !== -1) {
            return temp[curInd][isEven];
        }

        const noXor = nums[curInd] + calculateMax(curInd + 1, isEven);
        const withXor = (nums[curInd] ^ k) + calculateMax(curInd + 1, 1 - isEven);
        const mxPossible = Math.max(noXor, withXor);
        temp[curInd][isEven] = mxPossible;
        return mxPossible;
    }
    return calculateMax(0, 1);
};
