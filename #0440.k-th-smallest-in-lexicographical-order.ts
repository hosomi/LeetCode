function findKthNumber(n: number, k: number): number {
    function countNumbersWithPrefix(prefix: number, n: number): number {
        let current = prefix;
        let next = prefix + 1;
        let count = 0;
        while (current <= n) {
            count += Math.min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }

        return count;
    }

    let current = 1;
    k--;

    while (k > 0) {
        const count = countNumbersWithPrefix(current, n);

        if (k >= count) {
            k -= count;
            current++;
        } else {
            current *= 10;
            k--;
        }
    }
    return current;
};
