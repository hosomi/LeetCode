/**
 * @param {number} num
 * @return {string}
 */
var numberToWords = function(num) {
    if (num === 0) {
        return "Zero";
    }

    let str = "";
    const F = (x) => Math.floor(x);
    const dig = {
        1 : 'One',
        2 : 'Two',
        3 : 'Three',
        4 : 'Four',
        5 : 'Five',
        6 : 'Six',
        7 : 'Seven',
        8 : 'Eight',
        9 : 'Nine',
        10 : 'Ten',
        11 : 'Eleven',
        12 : 'Twelve',
        13 : 'Thirteen',
        14 : 'Fourteen',
        15 : 'Fifteen',
        16 : 'Sixteen',
        17 : 'Seventeen',
        18 : 'Eighteen',
        19 : 'Nineteen',
        20 : 'Twenty',
        30 : 'Thirty',
        40 : 'Forty',
        50 : 'Fifty',
        60 : 'Sixty',
        70 : 'Seventy',
        80 : 'Eighty',
        90 : 'Ninety'
    };

    const hundreds = (n) => {
        let temp = "";
        if (n >= 100) {
            temp += ` ${dig[F(n/100)]} Hundred`;
            n %= 100;
        }

        if (n >= 10 && n < 20) {
            temp += ` ${dig[n]}`;
            n = 0;
        }

        if (n >= 20) {
            temp += ` ${dig[F(n/10)*10]}`;
            n %= 10;
        }

        if (n) {
            temp += ` ${dig[F(n)]}`;
        }

        return temp;
    };

    if (num >= 1_000_000_000) {
        str += `${hundreds(F(num/1_000_000_000))} Billion`;
        num %= 1_000_000_000;
    }

    if (num >= 1_000_000) {
        str += `${hundreds(F(num/1_000_000))} Million`;
        num %= 1_000_000;
    }

    if (num >= 1_000) {
        str += `${hundreds(F(num/1_000))} Thousand`;
        num %= 1_000;
    }

    if (num) {
        str += `${hundreds(F(num))}`;
    }
    
    return str.trim();
};
