function reorderedPowerOf2(n: number): boolean {
    const s1 = n.toString().split('').sort().join('');
    for (let i = 0; i < 31; i++) {
        const s2 = Math.pow(2, i).toString().split('').sort().join('');
        if (s1 === s2) {
            return true;
        }
    }
    return false;
};
