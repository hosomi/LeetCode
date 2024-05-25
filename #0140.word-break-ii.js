/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {string[]}
 */
var wordBreak = function(s, wordDict) {
	function partition(index) {
		if (index >= s.length) {
			overallResult.push(result.join(' '));
			return;
		}
		
		for (let i = index; i < s.length; i++) {
			let spacenum = s.substring(index, i + 1);
			if (hash[spacenum]) {
				result.push(spacenum);
				partition(i + 1);
				result.pop();
			}
		}
		
	}

    let hash = {};
	for (let i = 0; i < wordDict.length; i++) {
		hash[wordDict[i]] = 1;
	}
	let overallResult = [];
	let result = [];
	partition(0);
    return overallResult;
};
