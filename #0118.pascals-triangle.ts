function generate(numRows: number): number[][] {
    var result = new Array(numRows);
    for (var i = 0; i <numRows; i++) {
        result[i]= new Array(i + 1);
        result[i][0] = 1;
        result[i][i] = 1;
        for (var j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    return result;
};
