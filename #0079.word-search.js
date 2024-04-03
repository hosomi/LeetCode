/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const row = board.length;
    const col = board[0].length;
    const dfs = (x, y, char) => {
        if (x < 0 || y < 0
            || x >= row
            || y >= col
            || board[x][y] != word[char]) {
                return false;
        }

        if (char + 1 == word.length) {
            return true;
        }

        const cel = board[x][y];
        board[x][y] = '-';
        const results = [
            dfs(x + 1, y, char + 1),
            dfs(x - 1, y, char + 1),
            dfs(x, y + 1, char + 1),
            dfs(x, y - 1, char + 1)
        ];
        board[x][y] = cel;
        return results.some(v => v == true);
    }

    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (dfs(i, j, 0)) {
                return true;
            }
        }
    }
    return false;
};
