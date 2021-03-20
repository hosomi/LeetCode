impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {

        nums.iter().fold((0, std::i32::MIN), |(it, max), &num| {
            (std::cmp::max(0, it + num) ,std::cmp::max(max, it + num))
        }).1
    }
}
