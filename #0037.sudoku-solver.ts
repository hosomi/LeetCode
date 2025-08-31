/**
 Do not return anything, modify board in-place instead.
 */
function solveSudoku(board: string[][]): void {
    const isValid = (x: number, y: number, value: string): boolean => {        
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                if (board[x][i * 3 + j] === value) {
                    return false;
                }

                if (board[i * 3 + j][y] === value) {
                    return false;
                }

                const squareX = Math.floor(x / 3) * 3;
                const squareY = Math.floor(y / 3) * 3;
                if (board[squareX + i][squareY + j] === value) {
                    return false;
                }
            }
        }
        
        return true;
    }

    const generate = (x: number = 0, y: number = 0): boolean => {
        if (y >= 9 || x >= 9) {
            return true;
        }
        
        const nextX = x === 8 ? 0 : x + 1;
        const nextY = nextX === 0 ? y + 1 : y;
        if (board[x][y] !== '.') {
            return generate(nextX, nextY);
        }
        
        for (let i = 1; i <= 9; i++) {
            if (isValid(x, y, String(i))) {
                board[x][y] = String(i);
                if (generate(nextX, nextY)) {
                    return true;
                }

                board[x][y] = '.';
            }
        }
        return false;
    }

    generate();
};
