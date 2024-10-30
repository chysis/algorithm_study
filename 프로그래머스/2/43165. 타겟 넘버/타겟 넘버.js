function solution(numbers, target) {
    let ans=0;
    
    const solve=(depth, sum)=>{
        if(depth===numbers.length) {
            if(sum===target) ans++;
            return;
        }
        
        solve(depth+1, sum+numbers[depth]);
        solve(depth+1, sum-numbers[depth]);
    };
    
    solve(0, 0);
    return ans;
}