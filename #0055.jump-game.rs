impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {

        let mut len = nums.len();
        if len <= 1 {
            return true;
        }
        let mut v = vec![true; len];
        Self::jump(&nums, len - 1, &mut v)
    }

    fn jump(nums: &Vec<i32>, index: usize, v: &mut Vec<bool>) -> bool {

        for i in 0..index {
            if nums[i] as usize >= index - i {
                if i == 0 {
                    return true;
                }
                if Self::jump(nums, i, v) {
                    return true;
                }
                break;
            }
        }
        return false;
    }
}
