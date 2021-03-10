impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {

        let mut v = Vec::new();
        let mut result = 0;
        let mut len = height.len();
        let mut last = 0;
        let mut trap = 0;
        let mut min = 0;
        let mut pop = 0;
        for i in 0..len {
            while v.len() > 0 && height[*v.last().unwrap()] < height[i] {
                pop = v.pop().unwrap();
                if v.is_empty() {
                    break;
                }
                last = *v.last().unwrap();
                trap = i - last - 1;
                min = std::cmp::min(height[i], height[last]) - height[pop];
                result += min * trap as i32
            }
            v.push(i);
        }

        return result;
    }
}
