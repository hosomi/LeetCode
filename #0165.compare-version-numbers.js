/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    const [arr1, arr2] = [version1.split('.'), version2.split('.')];
    const length = Math.max(arr1.length, arr2.length);
    for (let i = 0; i < length; i++) {
        const rev1 = parseInt(arr1[i]) || 0;
        const rev2 = parseInt(arr2[i]) || 0;
        if (rev1 < rev2) {
            return -1;
        }

        if (rev1 > rev2) {
            return 1;
        }
    }
    return 0;
};
