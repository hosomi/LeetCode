/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function(img) {
    return img.map((arr, i) =>
        arr.map((_, j) => {
            let sum = 0;
            let count = 0;
            for (let k = i - 1; k <= i + 1; k++) {
                for (let l = j - 1; l <= j + 1; l++) {
                    if(img[k] && img[k][l] > -1) {
                        sum += img[k][l];
                        count++;
                    }
                }
            }
            return ~~(sum / count);
        })
    );
};
