function isAnagram(s: string, t: string): boolean {
    const sortedT = [...t].sort();
    return [...s].sort().every((c, i) => sortedT[i] === c) && s.length === t.length;
};