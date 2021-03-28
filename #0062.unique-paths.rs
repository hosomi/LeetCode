impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {

        let (m, n) = (m as usize, n as usize);
        let mut up = vec![1; n];
        for i in 1..m {
            for j in 1..n {
                up[j] += up[j - 1];
            }
        }
        return up[n - 1];
    }
}
