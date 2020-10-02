/**
 * Returns first duplicated element.
 * @param {Array.<number>} array
 * @returns {number} Duplicated element or `-1`.
 */
function firstDuplicate(array) {
    let seen = [];

    for (n of array){
        if (seen.includes(n)){
            return n;
        } else {
            seen.push(n);
        }
    }
    
    return -1;
}

module.exports = {
    firstDuplicate
};
