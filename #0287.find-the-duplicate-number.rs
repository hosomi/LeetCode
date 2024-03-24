impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut seen = [false; 1e5 as usize];
        for num in nums {
            let idx = num as usize - 1;
            if seen[idx] {
                return num;
            }
            seen[idx] = true;
        }
        0
    }
}
