/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function(columnNumber) {
    let result = '';
    let title = columnNumber;
    while (title != 0) {
        let rem = title % 26 ? title % 26 : 26;
        title = (title - rem) / 26;
        result = String.fromCharCode(rem + 64) + result;
    }
    return result;
};
