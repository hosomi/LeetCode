/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    const arr = nums1.concat(nums2).sort((left, right) => left - right);
    const { length: length } = arr;
    return length % 2 === 0 ? 
        (arr[length / 2 - 1] + arr[length / 2]) / 2
        : arr[(length - 1) / 2];
};
