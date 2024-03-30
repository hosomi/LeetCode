/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysWithKDistinct = function(nums, k) {
    const subarraysWithKDistinct = (n, k) => {
        let left = right = result = distinct = 0;
        let arr = new Array(n.length + 1).fill(0);
        while (right < n.length) {
            if (arr[n[right]] === 0) {
                distinct++;
            }

            arr[n[right]]++;
            while (k < distinct) {
                arr[n[left]]--;
                if (arr[n[left]] === 0) {
                    distinct--;
                }
                left++;
            }
            result += right - left + 1;
            right++;
        }
        return result;
    }

    return subarraysWithKDistinct(nums, k)
        - subarraysWithKDistinct(nums, k - 1);
};
