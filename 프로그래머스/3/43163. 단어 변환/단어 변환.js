class Queue{
    #arr;
    #front;
    #rear;
    
    constructor(){
        this.#arr=[];
        this.#front=0;
        this.#rear=0;
    }
    
    push(elem){
        this.#arr[this.#rear]=elem;
        this.#rear++;
    }
    
    pop(){
        this.#front++;
        if(this.#front===this.#rear){
            this.#arr=[];
            this.#front=0;
            this.#rear=0;
        }
    }
    
    front(){
        return this.#arr[this.#front];
    }
    
    size(){
        return this.#rear-this.#front;
    }
    
    empty(){
        return this.size()===0;
    }
    
    clear(){
        this.#arr=[];
        this.#front=0;
        this.#rear=0;
    }
}

function dist_word(a, b){
    let temp=0;
    for(let i=0; i<a.length; i++){
        if(a[i]!==b[i]) temp++;
    }
    return temp;
}

function solution(begin, target, words) {
    let ans=0;
    const q = new Queue();
    q.push({w: begin, cnt: 0, visited: new Array(words.length).fill(false)});
    
    while(!q.empty()){
        const cur=q.front();
        q.pop();
        
        if(cur.w===target){
            ans=cur.cnt;
            break;
        }
        
        for(let i=0; i<words.length; i++){
            if(dist_word(cur.w, words[i])===1 && !cur.visited[i]){
                const new_visited=[...cur.visited];
                new_visited[i]=true;
                q.push({w: words[i], cnt: cur.cnt+1, visited: new_visited});
            }
        }
    }
    
    return ans;
}