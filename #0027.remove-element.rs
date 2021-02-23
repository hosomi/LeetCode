impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        
        nums.retain(|&x| x != val);
        return nums.len() as i32
    }
}
