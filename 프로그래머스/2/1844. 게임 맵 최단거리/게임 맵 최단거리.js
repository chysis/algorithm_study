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
        const removedItem=this.storage[this.start];
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
}

function solution(maps) {
    const N=maps.length;
    const M=maps[0].length;
    
    let q = new Queue();
    let answer=0;
    let visited=new Array(101).fill(0).map(()=>new Array(101).fill(false));
    const dx=[1, -1, 0, 0];
    const dy=[0, 0, 1, -1];
    
    const bfs=()=>{
        while(q.size()>0){
            let x=q.front().x;
            let y=q.front().y;
            let cnt=q.front().cnt;
            q.pop();
            
            if(x===N-1 && y===M-1) return cnt;
            
            for(let i=0; i<4; i++){
                let nx=x+dx[i];
                let ny=y+dy[i];
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                if(visited[nx][ny]) continue;
                if(maps[nx][ny]===0) continue;
                
                visited[nx][ny]=true;
                q.push({x: nx, y: ny, cnt: cnt+1});
            }
        }
        
        return -1;
    }
    
    q.push({x: 0, y: 0, cnt: 1});
    visited[0][0]=true;
    return bfs();
}