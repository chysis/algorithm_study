function solution(participant, completion) {
    const p={};
    participant.forEach(par=>{
        par in p ? p[par]++ : p[par]=1;
    });
    completion.forEach(par=>{
        p[par]--;
        p[par]===0 && delete p[par];
    });
    
    return Object.keys(p).join("");
}