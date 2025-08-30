function isValidSudoku(board: string[][]): boolean {
    let subBoxes = Array.from({ length: 9 }, () => new Set<string>());
    let rowDigits = Array.from({ length: 9 }, () => new Set<string>());
    let colDigits = Array.from({ length: 9 }, () => new Set<string>());

    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            let num = board[i][j];

            if (num !== ".") {
                let boxIndex = Math.floor(i / 3) * 3 + Math.floor(j / 3);

                if (rowDigits[i].has(num) || colDigits[j].has(num) || subBoxes[boxIndex].has(num)) {
                    return false;
                }

                rowDigits[i].add(num);
                colDigits[j].add(num);
                subBoxes[boxIndex].add(num);
            }
        }
    }
    return true;
};
