use std::collections::HashMap;
use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {

        let mut result: HashSet<Vec<i32>> = HashSet::new();

        for (i, x) in nums.iter().enumerate() {
            let target = 0 - *x;
            let mut hm: HashMap<i32, i32> = HashMap::new();
            for y in &nums[i + 1..] {
                match hm.get(y) {
                    Some(&z) => {
                        let mut v = vec![*x, *y, z];
                        v.sort();
                        result.insert(v);
                    }
                    None => {
                        hm.insert(target - *y, *y);
                    }
                }
            }
        }
        return Vec::from_iter(result.into_iter())
    }
}
