/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    let stack = [];
    for (let i = 0; i < tokens.length; i++) {
        if (parseInt(tokens[i]) >= -200) {
            stack.push(tokens[i]);
            continue;
        }
        let pop1 = stack.pop();
        let pop2 = stack.pop();
        let trunc = Math.trunc(
            eval(pop2 + tokens[i] + " " + pop1)
        );
        stack.push(trunc);
    }
    return stack.pop();
};
