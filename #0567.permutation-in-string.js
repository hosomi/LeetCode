/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    if (s1.length > s2.length) {
        return false;
    }

    function isAnagram(charMap, cMap) {
        for (let [key, value] of cMap) {
            if (!charMap.has(key) || charMap.get(key) !== value) {
                return false;
            }
        }
        return true;
    }

    let freq_s1 = new Map();
    for (let i = 0; i < s1.length; i++) {
        freq_s1.set(s1[i], (freq_s1.get(s1[i]) || 0) + 1);
    }

    let freq_s2 = new Map();
    for (let i = 0, left = 0; i < s2.length; i++) {
        freq_s2.set(s2[i], (freq_s2.get(s2[i]) || 0) + 1);
        if (i - left + 1 === s1.length) {
            if (isAnagram(freq_s2, freq_s1)) {
                return true;
            }
            freq_s2.set(s2[left], freq_s2.get(s2[left]) - 1);
            left++;
        }
    }
    return false;
};
