/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    const slength = s.length;
    const tlength = t.length;
    if (!s || !t || slength < tlength) {
        return "";
    }

    const freqMap = {};
    for (const ch of t) {
        freqMap[ch] = (freqMap[ch] || 0) + 1;
    }

    let left = 0;
    let right = 0;
    let count = 0;
    let i = slength + 1;
    let j = slength + 1;
    while (right < slength) {
        if (freqMap[s[right]]-- >= 1) {
            count++;
        }
        right += 1;

        while (count == tlength) {
            if (right - left < j) {
                j = right - left;
                i = left;
            }
            if (freqMap[s[left]]++ >= 0) {
                count -= 1;
            }
            left += 1;
        }
    }
    return s.slice(i, i + j);
};
