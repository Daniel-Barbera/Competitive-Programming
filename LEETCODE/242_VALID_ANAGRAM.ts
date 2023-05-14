// Simpler, but O(NlogN)
function isAnagram(s: string, t: string): boolean {
    const sortedT = [...t].sort();
    return [...s].sort().every((c, i) => sortedT[i] === c) && s.length === t.length;
};

// A bit more elaborate, but O(N)
function isAnagram(s: string, t: string): boolean {
    if (s.length != t.length) return false;
    const mapOfS = new Map();
    [...s].forEach((char) => mapOfS.set(char, (mapOfS.get(char) ?? 0) + 1));
    [...t].forEach((char) => mapOfS.set(char, (mapOfS.get(char) ?? 0) - 1));
    for (const [k, v] of mapOfS) {
        if (v) return false; 
    }
    return true; 
};