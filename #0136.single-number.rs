impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {

        let mut result: i32 = 0;
        for i in nums {
            result ^= i;
        }
        return result;
    }
}
