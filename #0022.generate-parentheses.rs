impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {

        let mut left = n;
        let mut right = n;
        let mut res = Vec::new();
        let mut cur = Vec::new();
        Self::addingpar(left, right, &cur, &mut res);
        return res
    }

    fn addingpar(left: i32, right: i32, cur: &Vec<u8>, res: &mut Vec<String>) {

        if left == right && left == 0 {
            res.push(unsafe { String::from_utf8_unchecked(cur.clone()) });
            return;
        }

        if left > 0 {
            let mut cur = cur.clone();
            cur.push('(' as u8);
            Self::addingpar(left - 1, right, &cur, res);
        }

        if left < right {
            let mut cur = cur.clone();
            cur.push(')' as u8);
            Self::addingpar(left, right - 1, &cur, res);
        }
    }
}
