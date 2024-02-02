/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
var sequentialDigits = function(low, high) {
    const results = [];
    const numDigits= "123456789".split(""); 
    const hlength = String(high).length;
    let llength = String(low).length;
    while (llength <= hlength) {
        for (let i = 0; i <= numDigits.length - llength; i += 1) {
            const num = Number(numDigits.slice(i,
                i + llength).join(""));
            if (num >= low && num <= high) {
                results.push(num);
            }
        }
        llength += 1;
    }
    return results;
};
