/**
 * @param {number[]} deck
 * @return {number[]}
 */
var deckRevealedIncreasing = function(deck) {
    deck.sort((left, right) => left - right);
    const arr = [];
    while (deck.length) {
        arr.unshift(deck.pop());
        arr.unshift(arr.pop());
    }
    arr.push(arr.shift());
    return arr;
};
