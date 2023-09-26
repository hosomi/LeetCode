/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicateLetters = function(s) {
    const length = s.length;
    let st = [];
    let occurence = {};
    let seen = {};
    for (let i = 0; i < length; i++) {
        occurence[s[i]] = i;
    }

    for (let i = 0; i < length; i++) {
        if (seen[s[i]]) {
            continue;
        }

        while (st.length > 0
            && s[i] < st[st.length - 1]
            && occurence[st[st.length - 1]] > i) {
            let ch = st.pop();
            seen[ch] = false;
        }

        seen[s[i]] = true;
        st.push(s[i]);
    }
    return st.join("");
};
