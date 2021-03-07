impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {

        let len = nums.len();
        match len {
            1 => {
                return;
            }
            2 => {
                Self::swap(nums, 0, 1);
                return;
            }
            _ => {}
        }

        let mut index = 0;
        if nums[len - 1] > nums[len - 2] {
            Self::swap(nums, len - 1, len - 2);
            return;
        } else {
            for i in (1..len - 1).rev() {
                if nums[i] > nums[i - 1] {
                    index = i;
                    break;
                }
            }
            Self::reverse(nums, index, len - 1);
            if index == 0 {
                return;
            }
            for i in index..len {
                if nums[i] > nums[index - 1] {
                    Self::swap(nums, i, index - 1);
                    break;
                }
            }
        }
    }

    fn reverse(nums: &mut Vec<i32>, i: usize, j: usize) {
        let mut i = i;
        let mut j = j;
        while i < j {
            Self::swap(nums, i, j);
            i += 1;
            j -= 1;
        }
    }

    fn swap(nums: &mut Vec<i32>, i: usize, j: usize) {
        let t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
