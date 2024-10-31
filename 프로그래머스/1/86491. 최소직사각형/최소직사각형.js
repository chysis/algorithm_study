function solution(sizes) {
    const sorted=sizes.map(size=>size.sort((a, b)=>a-b));
    const maxWidth=Math.max(...sorted.map(i=>i[0]));
    const maxHeight=Math.max(...sorted.map(i=>i[1]));
    return maxWidth*maxHeight;
}