function solution(prices) {
    const s=[], ans=new Array(prices.length).fill(-1);
    for(let i=0; i<prices.length; i++){
        if(s.length===0){
            s.push({v: prices[i], idx: i});
            continue;
        }
        
        while(s.length>0 && s[s.length-1].v>prices[i]){
            ans[s[s.length-1].idx]=i-s[s.length-1].idx;
            s.pop();
        }
        s.push({v: prices[i], idx: i});
    }
    
    while(s.length>0){
        ans[s[s.length-1].idx]=prices.length-1-s[s.length-1].idx;
        s.pop();
    }
    
    return ans;
}