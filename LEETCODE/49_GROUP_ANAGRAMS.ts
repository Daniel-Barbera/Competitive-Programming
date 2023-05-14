function getCharacterCount(s: string): Record<string, number> {
    const mapOfS: Record<string, number> = {}; 
    [...s].forEach((char) => {mapOfS[char] = (mapOfS[char] ?? 0) + 1;}); 
    return mapOfS; 
};

function groupAnagrams(strs: string[]): string[][] {
    const anagramGroups: Record<string, string[]> = {};

    for (const word of strs) {
        const countMap = getCharacterCount(word);
        // The following generates a hash value that is generally faster than sorting all N characters of a word.
        const key = [...Object.entries(countMap)].sort().toString();

        if (anagramGroups[key]) {
            anagramGroups[key].push(word);
        } else {
            anagramGroups[key] = [word];
        }
    }
    return [...Object.values(anagramGroups)]; 
};

// O(N)...ish implementation.
function groupAnagrams(strs: string[]): string[][] {
    const anagramGroups: Record<string, string[]> = {};

    for (const word of strs) {
        const count = Array(26).fill(0); // 26 letters in the alphabet.
        let key = '';

        for (const char of word) {
            const charCode = char.charCodeAt(0) - 'a'.charCodeAt(0); // Strings are made of strings in JS... ugh.
            count[charCode]++;
        }

        // Generate a unique hash value for each group of anagrams, without sorting.
        for (let i = 0; i < 26; i++) {
        key += '#' + count[i];
        }

        if (anagramGroups[key]) {
            anagramGroups[key].push(word);
        } else {
            anagramGroups[key] = [word];
        }
    }

    return Object.values(anagramGroups);
}