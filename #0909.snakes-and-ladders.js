/**
 * @param {number[][]} board
 * @return {number}
 */
var snakesAndLadders = function(board) {
    const n = board.length;

    const getCoordinates = (square) => {
        let row = Math.floor((square - 1) / n);
        let col = (square - 1) % n;
        
        if (row % 2 === 1) {
            col = n - 1 - col;
        }
        
        return [n - 1 - row, col];
    };

    const queue = [[1, 0]];
    const visited = new Set([1]);
    while (queue.length > 0) {
        const [square, moves] = queue.shift();
        
        if (square === n * n) {
            return moves;
        }
        
        for (let nextSquare = square + 1; 
             nextSquare <= Math.min(square + 6, n * n); 
             nextSquare++) {
            
            const [r, c] = getCoordinates(nextSquare);   
            const destination = board[r][c] === -1 ? 
                nextSquare : board[r][c];
            
            if (!visited.has(destination)) {
                visited.add(destination);
                queue.push([destination, moves + 1]);
            }
        }
    }
    return -1;
};
