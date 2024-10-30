function solution(citations) {
    const sorted=citations.sort((a, b)=>b-a);
    for(let i=0; i<sorted.length; i++){
        if(i+1>sorted[i]){
            return i;
        } else if(i+1===sorted[i]){
            return i+1;
        }
    }
    return citations.length;
}