impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {

        let (len1, len2) = (word1.len(), word2.len());
        let (bytes1, bytes2) = (word1.into_bytes(), word2.into_bytes());
        let mut result = vec![vec![0; len2 + 1]; len1 + 1];
        for i in 0..=len1 {
            result[i][0] = i as i32;
        }

        for j in 0..=len2 {
            result[0][j] = j as i32;
        }

        for i in 1..=len1 {
            for j in 1..=len2 {
                if bytes1[i - 1] == bytes2[j - 1] {
                    result[i][j] = result[i - 1][j - 1]
                } else {
                    result[i][j] = result[i - 1][j].min(result[i][j - 1]).min(result[i - 1][j - 1]) + 1;
                }
            }
        }
        return result[len1][len2];
    }
}
