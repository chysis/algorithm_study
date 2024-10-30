function solution(numbers) {
    const sorted = numbers.map(String).sort((a, b)=>Number(b+a)-Number(a+b));
    return sorted.every(elem=>elem==="0") ? "0" : sorted.join("");
}