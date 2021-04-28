impl Solution {
    pub fn num_trees(n: i32) -> i32 {

        let n = n as usize;
        let mut result = vec![0; n + 1];
        result[0] = 1;
        for i in 1..=n {
            for j in 1..=i {
                result[i] += result[j - 1] * result[i - j];
            }
        }

        return result[n];
    }
}
