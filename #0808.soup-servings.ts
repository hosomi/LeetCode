function soupServings(n: number): number {
    if (n > 4450) return 1;
    const memo = new Map<string, number>(),
        calc = (a: number, b: number): number => {
            if (a <= 0 && b <= 0) {
                return .5;
            }
            if (a <= 0) {
                return 1;
            }
            if (b <= 0) {
                return 0;
            }
            
            const key = a + ':' + b;
            if (memo.has(key)) {
                return memo.get( key ) as number;
            }

            let res = (
                calc(a - 100, b) +
                calc(a - 75, b - 25) +
                calc(a - 50, b - 50) +
                calc(a - 25, b - 75)
            ) / 4;
            memo.set(key, res);
            return res;
        }
    ;
    return calc( n, n );
};
