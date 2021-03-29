impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {

        let rowSize = obstacle_grid.len();
        let colSize = obstacle_grid[0].len();

        let mut result = vec![vec![0; colSize]; rowSize];
        result[rowSize - 1][colSize - 1] = 1 - obstacle_grid[rowSize - 1][colSize - 1];
        for i in (0..rowSize).rev() {
            for j in (0..colSize).rev() {
                if obstacle_grid[i][j] == 0 {
                    if i < rowSize - 1 {
                        result[i][j] += result[i + 1][j];
                    }
                    if j < colSize - 1 {
                        result[i][j] += result[i][j + 1];
                    }
                }
            }
        }

        return result[0][0];
    }
}
