impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {

        let mut result = vec![vec![]];
        let mut work = vec![vec![]];
        for num in nums {
            work = result.clone();
            work.iter_mut().for_each(|x| x.push(num));
            result.append(&mut work);
        }
        return result;
    }
}
