/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    
    if (object === null) {
        return "null";
    }

    if (typeof object !== 'object') {
        return typeof(object) === 'string' ? `"${object}"` : object
    }

    let result = '';
    const isArray = Array.isArray(object);
    result += isArray? '[':'{';
    const keys = Object.keys(object)
    keys.forEach((k, i) => {
        result += !isArray ? `"${k}":${jsonStringify(object[k])}` : jsonStringify(object[k])
        if (i !== keys.length-1 ) {
            result += ',';
        }
       
    })
    result += isArray ? ']' : '}';
    return result;
};
