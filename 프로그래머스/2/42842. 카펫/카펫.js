function solution(brown, yellow) {
    for(let i=3; i<2000; i++){
        for(let j=3; j<=i; j++){
            if((i-2)*(j-2)===yellow && 2*(i+j)-4===brown) return [i, j];
        }
    }
}