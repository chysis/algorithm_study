function solution(k, dungeons) {
    const visited=new Array(8).fill(false);
    const sel=new Array(8);
    let ans=0;
    
    const solve = (cnt)=>{
        if(cnt===dungeons.length){
            let temp=k, dun_cnt=0;
            for(let i=0; i<dungeons.length; i++){
                if(temp<dungeons[sel[i]][0] || temp<dungeons[sel[i]][1]) continue;
                temp-=dungeons[sel[i]][1];
                dun_cnt++;
            }

            ans=Math.max(ans, dun_cnt);
            return;
        }
        
        for(let i=0; i<dungeons.length; i++){
            if(!visited[i]){
                visited[i]=true;
                sel[cnt]=i;
                solve(cnt+1);
                visited[i]=false;
            }
        }
    }
    
    solve(0);
    return ans;
}