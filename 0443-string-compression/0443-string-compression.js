/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function(chars) {
    let i = 0;
    let ansIndex = 0;
    const n = chars.length;

    while (i < n) {
        let j = i + 1;

        // Find the next different character
        while (j < n && chars[i] === chars[j]) {
            j++;
        }

        // Store the current character
        chars[ansIndex++] = chars[i];

        const count = j - i;

        // If count > 1, store each digit of count
        if (count > 1) {
            const countStr = count.toString();
            for (let ch of countStr) {
                chars[ansIndex++] = ch;
            }
        }

        i = j;
    }

    // Resize the array to the compressed length
    chars.length = ansIndex;

    return ansIndex;
};
