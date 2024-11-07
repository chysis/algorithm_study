class Queue{
    constructor(){
        this.storage={};
        this.start=0;
        this.end=0;
    }
    
    size(){
        return this.end-this.start;
    }
    
    push(item){
        this.storage[this.end]=item;
        this.end++;
    }
    
    pop(){
        let removedItem=this.storage[this.start];
        delete this.storage[this.start];
        this.start++;
        
        if(this.start===this.end){
            this.start=0;
            this.end=0;
        }
        
        return removedItem;
    }
    
    front(){
        return this.storage[this.start];
    }
    
    back(){
        return this.storage[this.end];
    }
    
    clear(){
        this.storage={};
        this.start=0;
        this.end=0;
    }
}

function solution(land) {
    const N=land.length;
    const M=land[0].length;
    
    let ans=-1;
    let visited=new Array(N).fill(0).map(()=>new Array(M).fill(false));
    let areaMap=new Array(N).fill(0).map(()=>new Array(M).fill(-1));
    let areaSize=new Array(130000).fill(0);
    let areaNum=0;
    let q=new Queue();
    
    const dx=[-1, 1, 0, 0];
    const dy=[0, 0, -1, 1];
    
    const bfs=()=>{
        while(q.size()>0){
            let x=q.front().x;
            let y=q.front().y;
            let cnt=q.front().cnt;
            q.pop();
            
            for(let i=0; i<4; i++){
                const nx=x+dx[i];
                const ny=y+dy[i];
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                if(visited[nx][ny]) continue;
                if(land[nx][ny]===0) continue;
                
                visited[nx][ny]=true;
                q.push({x: nx, y: ny, cnt: cnt+1});
                areaMap[nx][ny]=areaNum;
            }
        }
    }
    
    for(let i=0; i<N; i++){
        for(let j=0; j<M; j++){
            if(!visited[i][j] && land[i][j]===1){
                visited[i][j]=true;
                q.push({x: i, y: j, cnt: 1});
                areaMap[i][j]=areaNum;
                bfs();
                
                areaNum++;
            }
        }
    }

    for(let i=0; i<N; i++){
        for(let j=0; j<M; j++){
            if(areaMap[i][j]!==-1){
                areaSize[areaMap[i][j]]++;
            }
        }
    }
    
    for(let i=0; i<M; i++){
        let temp=0;
        let s=new Set();
        for(let j=0; j<N; j++){
            if(areaMap[j][i]!==-1){
                s.add(areaMap[j][i]);
            }
        }
        
        for(const num of s){
            temp+=areaSize[num];
        }
        ans=Math.max(ans, temp);
    }
    
    return ans;
}