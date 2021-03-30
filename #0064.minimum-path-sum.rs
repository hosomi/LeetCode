impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {

        let rowlen = grid.len();
        let collen = grid[0].len();
        let mut board = grid.clone();
        for i in 0..rowlen {
            for j in 0..collen {
                board[i][j] += match (i, j) {
                    (0, 0) => 0,
                    (0, _) => board[i][j - 1],
                    (_, 0) => board[i - 1][j],
                    _ => board[i][j - 1].min(board[i - 1][j]),
                };
            }
        }

        return board[rowlen - 1][collen - 1];
    }
}
