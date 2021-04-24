impl Solution {
    pub fn subsets_with_dup(nums: Vec<i32>) -> Vec<Vec<i32>> {

        let mut nums = nums;
        nums.sort_unstable();

        let mut index = 1;
        let mut len = nums.len();
        let mut retlet = 0;
        let mut v = vec![];
        let mut result = vec![vec![]];
        for i in 0..len {
            if i > 0 && nums[i] == nums[i - 1] {
                index += 1;
            } else {
                index = 1;
            }
            retlet = result.len();
            v = result.split_at(retlet - retlet / index).1.to_vec();
            v.iter_mut().for_each(|x| x.push(nums[i]));
            result.append(&mut v);
        }

        return result;
    }
}
