/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * function MountainArray() {
 *     @param {number} index
 *     @return {number}
 *     this.get = function(index) {
 *         ...
 *     };
 *
 *     @return {number}
 *     this.length = function() {
 *         ...
 *     };
 * };
 */

/**
 * @param {number} target
 * @param {MountainArray} mountainArr
 * @return {number}
 */
var findInMountainArray = function(target, mountainArr) {
    const cache = {};
    const getCachedValue = (i) => {
        if (undefined === cache[i]) {
            cache[i] = mountainArr.get(i);
        }
        return cache[i];
    }

    const binarySearch = (lo, hi, desc) => {
        while (lo <= hi) {
            let mid = Math.trunc(lo + (hi - lo) / 2);
            const val = getCachedValue(mid);
            if (val == target)  {
                return mid;
            } else if (desc && val > target || !desc && val <= target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }

    let max = 0, n = mountainArr.length();
    cache[n] = Number.MIN_VALUE;
    let right = n;
    while (max < right) {
        let mid = Math.trunc(max + (right - max) / 2);
        if (getCachedValue(mid) > getCachedValue(mid + 1)) {
            right = mid;
        } else {
            max = mid + 1;
        }
    }

    const result = binarySearch(0, max, false);
    return result == -1 ? binarySearch(max, n - 1, true) : result;
};
