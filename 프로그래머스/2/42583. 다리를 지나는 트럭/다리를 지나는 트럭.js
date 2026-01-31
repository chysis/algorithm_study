class Queue{
    #arr=[];
    #front=0;
    #rear=0;
    
    queue(){
        this.#arr=[];
        this.#front=0;
        this.#rear=0;
    }
    
    push(elem){
        this.#arr[this.#rear++]=elem;
    }
    
    pop(){
        if(this.size()===0) return;
        
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
    
    weight_sum(){
        let res=0;
        for(let i=this.#front; i<this.#rear; i++){
            res+=this.#arr[i].weight;
        }
        return res;
    }
}

function solution(bridge_length, weight, truck_weights) {
    const q=new Queue();
    let cur=1;
    for(let i=0; i<truck_weights.length; i++){
        const cur_weight=truck_weights[i];
        
        while(!q.empty() && q.front().enter+bridge_length <= cur){
            q.pop();
        }
        
        if(q.weight_sum()+cur_weight<=weight){
            q.push({weight: cur_weight, enter: cur});
            cur++;
        }else{
            while(q.weight_sum()+cur_weight>weight){
                cur=q.front().enter+bridge_length;
                q.pop();    
            }
            q.push({weight: cur_weight, enter: cur});
            cur++;
        }
    }
    
    while(!q.empty()){
        cur=q.front().enter+bridge_length;
        q.pop();  
    }
    return cur;
}