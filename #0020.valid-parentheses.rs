use std::collections::HashMap;

impl Solution {
    pub fn is_valid(s: String) -> bool {

        let determine: HashMap<char, char> = [
            ('(', ')'), ('[', ']'), ('{', '}'),
        ].iter().cloned().collect();
        let mut sc: Vec<char> = vec![];
        for c in s.chars() {
            if determine.contains_key(&c) {
                sc.push(c)
            } else if sc.pop().and_then(|k| determine.get(&k)).unwrap_or(&'#') != &c { 
                return false;
            }
        }
        sc.is_empty()
    }
}
