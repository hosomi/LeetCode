/**
 * @param {string} s
 * @return {boolean}
 */
var halvesAreAlike = function(s) {
    const vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    let loop = s.length / 2;
    let counter = 0;
    for (i = 0; i < loop; i++){
        if (vowels.includes(s[i])) {
            counter++;
        }
        if (vowels.includes(s[i + loop])) {
            counter--;
        }
    }
    return counter == 0;
};
