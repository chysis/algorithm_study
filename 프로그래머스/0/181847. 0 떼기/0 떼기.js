function solution(n_str) {
    const idx = [...n_str].findIndex(c => c!=="0");
    return n_str.slice(idx);
}