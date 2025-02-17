/**
 * @param {string} tiles
 * @return {number}
 */
var numTilePossibilities = function(tiles) {
    return search(tiles);
};

const isValidState = (state = "", res=[]) => !!state && !res.includes(state);
const search = (tiles = "", state = '', result=[]) => {
    if (isValidState(state,result)) {
        result.push(state);
    }
   
    for (let i = 0; i < tiles.length; i++) {
        state += tiles[i];
        const newTiles = tiles.substring(0, i) + tiles.substring(i + 1);
        search(newTiles, state,result);
        state = state.slice(0, state.length - 1);
    }
    return result.length;
}
