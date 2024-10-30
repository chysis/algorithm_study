class Queue{
    constructor(){
        this.storage={};
        this.start=0;
        this.end=0; // 마지막 원소 다음 인덱스를 가리킴
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

function solution(n, computers) {
    let q = new Queue();
    let visited = new Array(n).fill(false);
    let ans=0;
    
    const bfs=()=>{
        while(q.size()>0){
            let cur=q.front();
            q.pop();
            
            for(let i=0; i<n; i++){
                if(i===cur) continue;
                if(computers[cur][i]===0) continue;
                if(visited[i]) continue;
                
                q.push(i);
                visited[i]=true;
            }
        }
    }
    
    for(let i=0; i<n; i++){
        if(visited[i]) continue;
        
        q.push(i);
        visited[i]=true;
        bfs();
        ans++;
        q.clear();
    }
        
    return ans;
}