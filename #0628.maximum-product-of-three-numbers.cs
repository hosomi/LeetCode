public class Solution {
    public int MaximumProduct(int[] nums) {
        
        int length = nums.Length;
        Array.Sort(nums);
        return Math.Max(nums[0] * nums[1] * nums[length - 1], nums[length - 1] * nums[length - 2] * nums[length - 3]);
    }
}
