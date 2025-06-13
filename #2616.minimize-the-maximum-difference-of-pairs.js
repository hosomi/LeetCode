/**
 * @param {number[]} nums
 * @param {number} p
 * @return {number}
 */
var minimizeMax = function(nums, p) {
     nums.sort((a, b) => { return (a - b) });
     let n = nums?.length;
     let start = 0,end = nums[n -1] - nums[0];
     while (start < end) {
         let mid = Math.floor((start + end) / 2);
         let k = 0;
         for (let i = 1; i < nums?.length && k < p; i++) {
             if ((nums[i] - nums[i-1]) <= mid) {
                 k++;
                 i++;
             }   
         }

         if (k >= p) {
             end = mid;
         } else{
             start = mid + 1;
         }
     } 
     return start;
};
