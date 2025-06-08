function lexicalOrder(n: number): number[] {
    const result: number[] = [];
    function dfs(current: number) {
        if (current > n) {
            return;
        }

        result.push(current);
        for (let i = 0; i <= 9; i++) {
            const next = current * 10 + i;
            if (next > n) {
                break;
            }
            dfs(next)
        }
    }

    for (let i = 1; i <= 9; i++) {
        if (i > n) {
            break;
        }
        dfs(i);
    }

    return result;
};
