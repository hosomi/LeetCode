function largestGoodInteger(num: string): string {
    let res = "";
    for (let i = 0; i < 10; i++) {
        const str = "" + i + i + i;
        if (num.includes(str)) {
            res = str;
        }
    }
    return res;
};
