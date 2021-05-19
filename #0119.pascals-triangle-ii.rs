impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {

        let row_index = row_index as usize;
        let mut result = vec![];
        let mut work = 0;
        result.push(1);
        for i in 1..row_index + 1 {
            work = result[i - 1] as usize * (row_index + 1 - i) / i;
            result.push(work as i32);
        }
        return result;
    }
}
