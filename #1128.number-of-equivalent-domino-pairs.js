/**
 * @param {number[][]} dominoes
 * @return {number}
 */
var numEquivDominoPairs = function(dominoes) {
    const dic = {};
    let pairs = 0;
    dominoes.map((domi) => {
        domi.sort((a, b) => a - b);
        dic[domi] ? ((pairs += dic[domi]), dic[domi]++) : (dic[domi] = 1);
    });
    return pairs;
};
