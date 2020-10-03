function isAnagram( param_str1, param_str2 ) {

    // Strip all whitespace characters from both strings & convert to lowercase for comparison
    let str1 = param_str1.replace(/\s+/g, '').toLowerCase();
    let str2 = param_str2.replace(/\s+/g, '').toLowerCase();

    // If str1 equals str2, it's an anagram of itself
    if ( str1 === str2 ) {
        return true;
    }

    // If the length of the strings is not equal, they're not anagrams
    if ( str1.length !== str2.length ) {
        return false;
    }

    // Do split() on each word on each character; let JS sort the characters; then join() back into a string again
    str1 = str1.split("").sort().join("");
    str2 = str2.split("").sort().join("");

    // If the strings match each other now, they are anagrams of each other
    if ( str1 === str2 ) {
        return true;
    }

    // If we got all the way here, the strings are not anagrams
    return false;

}
