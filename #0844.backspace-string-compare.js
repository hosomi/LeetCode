/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {
    let st1 = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] == '#') {
            st1.pop();
        } else {
            st1.push(s[i]);
        }
    }

    let st2 = [];
    for (let i = 0; i < t.length; i++) {
        if (t[i] == '#') {
            st2.pop();
        } else {
            st2.push(t[i]);
        }
    }  

    return st1.join("") == st2.join("");
};
