impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {

        if n == 1 {
            return 1;
        } else if n == 2 {
            return 2;
        }

        let mut step = 1;
        let mut last = 2;
        let mut start = 2;
        while start < n {
            let swap = step + last;
            step = last;
            last = swap;
            start += 1;
        }

        return last;
    }
}
