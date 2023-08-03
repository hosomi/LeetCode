/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    const phone = {
        2: ['a','b','c'],
        3: ['d','e','f'],
        4: ['g','h','i'],
        5: ['j','k','l'],
        6: ['m','n','o'],
        7: ['p','q','r','s'],
        8: ['t','u','v'],
        9: ['w','x','y','z'],
    };

    if (!digits) {
        return [];
    }

    let result = phone[digits[0]]
        .map(d => d);
    for (let i = 1; i < digits.length; i++) {
        const digit = digits[i];
        result = result
            .flatMap(d => phone[digit]
            .map(v => d + v)
        );
    }
    return result;
};
