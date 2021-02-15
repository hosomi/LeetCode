use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {

        let mut m: HashMap<i32, i32> = HashMap::new();
        let mut result: Vec<i32> = Vec::new();

        for (i, num) in nums.iter().enumerate() {
            if (m.contains_key(&(target - num))) {
                result.push(m[&(target - num)]);
                result.push(i as i32);
                return result;
            }
            m.insert(*num, i as i32);
        }
        return result;
    }
}
