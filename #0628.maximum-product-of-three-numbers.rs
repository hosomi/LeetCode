use std::cmp;

impl Solution {
    pub fn maximum_product(nums: Vec<i32>) -> i32 {

        let mut nums = nums;
        nums.sort();
        
        let len = nums.len();
        let last = nums[(len-3)..len].iter().fold(1, | mut sum, &val | {sum *= val; sum});
        let first = nums[len-1] * nums[0..2].iter().fold(1, | mut sum, &val | {sum *= val; sum});

        return cmp::max(first, last);
    }
}
